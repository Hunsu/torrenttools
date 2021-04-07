#pragma once

#include <filesystem>
#include <dottorrent/general.hpp>
#include <dottorrent/dht_node.hpp>
#include <dottorrent/metafile.hpp>

#include "list_edit_mode.hpp"
#include "common.hpp"


// Forward declarations
namespace CLI { class App; }

namespace dt = dottorrent;
namespace tt = torrenttools;

struct edit_app_options
{
    std::filesystem::path metafile;
    std::optional<std::filesystem::path> destination;
    tt::list_edit_mode list_mode = tt::list_edit_mode::replace;
    std::optional<std::vector<std::vector<std::string>>> announce_list;
    std::optional<std::vector<std::string>> announce_group_list;
    std::optional<std::vector<dottorrent::dht_node>> dht_nodes;
    std::optional<std::vector<std::string>> web_seeds;
    std::optional<std::string> comment;
    bool set_creation_date = true;
    std::optional<std::chrono::system_clock::time_point> creation_date;
    bool set_created_by = true;
    std::optional<std::string> created_by;
    std::optional<bool> is_private;
    std::optional<std::string> source;
    std::optional<std::string> name;
    bool write_to_stdout = false;
};

void configure_edit_app(CLI::App* app, edit_app_options& options);

void run_edit_app(const main_app_options& main_options, const edit_app_options& options);

void update_announces(dt::metafile& m, const main_app_options& main_options, const edit_app_options& options);

void update_announce_group(dt::metafile& m, const main_app_options& main_options, const edit_app_options& options);

void update_web_seeds(dt::metafile& m, const edit_app_options& options);

void update_dht_nodes(dt::metafile& m, const edit_app_options& options);

