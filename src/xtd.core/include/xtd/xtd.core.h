/// @file
/// @brief Contains xtd.core library headers.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "std.h"

#include "collections/any_pair.h"
#include "collections/array_list.h"
#include "collections/enumerator.h"
#include "collections/hashtable.h"
#include "collections/icollection.h"
#include "collections/ienumerable.h"
#include "collections/ienumerator.h"
#include "collections/iequality_comparer.h"
#include "collections/key_not_found_exception.h"
#include "collections/generic/dictionary.h"
#include "collections/generic/enumerator.h"
#include "collections/generic/hash_set.h"
#include "collections/generic/icollection.h"
#include "collections/generic/ienumerable.h"
#include "collections/generic/ienumerator.h"
#include "collections/generic/iequality_comparer.h"
#include "collections/generic/ilist.h"
#include "collections/generic/key_value_pair.h"
#include "collections/generic/list.h"
#include "collections/generic/sorted_dictionary.h"
#include "collections/generic/sorted_set.h"
#include "collections/generic/helpers/allocator.h"
#include "collections/generic/helpers/comparer.h"
#include "collections/generic/helpers/equator.h"
#include "collections/generic/helpers/hasher.h"
#include "collections/object_model/read_only_collection.h"
#include "collections/specialized/string_collection.h"
#include "collections/specialized/string_dictionary.h"
#include "collections/specialized/string_key_value_pair.h"
#include "configuration/ini_file_settings.h"
#include "configuration/file_settings.h"
#include "configuration/settings.h"
#include "diagnostics/assert.h"
#include "diagnostics/assert_dialog_result.h"
#include "diagnostics/boolean_switch.h"
#include "diagnostics/console_trace_listener.h"
#include "diagnostics/data_received_event_args.h"
#include "diagnostics/data_received_event_handler.h"
#include "diagnostics/debug.h"
#include "diagnostics/debug_break.h"
#include "diagnostics/debugger.h"
#include "diagnostics/default_trace_listener.h"
#include "diagnostics/event_type_filter.h"
#include "diagnostics/ostream_trace_listener.h"
#include "diagnostics/process.h"
#include "diagnostics/process_priority_class.h"
#include "diagnostics/process_start_info.h"
#include "diagnostics/process_window_style.h"
#include "diagnostics/source_filter.h"
#include "diagnostics/source_levels.h"
#include "diagnostics/source_switch.h"
#include "diagnostics/stack_frame.h"
#include "diagnostics/stack_trace.h"
#include "diagnostics/stopwatch.h"
#include "diagnostics/switch_base.h"
#include "diagnostics/trace.h"
#include "diagnostics/trace_event_cache.h"
#include "diagnostics/trace_event_type.h"
#include "diagnostics/trace_filter.h"
#include "diagnostics/trace_level.h"
#include "diagnostics/trace_listener.h"
#include "diagnostics/trace_listener_collection.h"
#include "diagnostics/trace_options.h"
#include "diagnostics/trace_source.h"
#include "diagnostics/trace_switch.h"
#include "io/binary_reader.h"
#include "io/binary_writer.h"
#include "io/directory.h"
#include "io/directory_info.h"
#include "io/directory_not_found_exception.h"
#include "io/drive_info.h"
#include "io/drive_not_found_exception.h"
#include "io/drive_type.h"
#include "io/end_of_stream_exception.h"
#include "io/file.h"
#include "io/file_access.h"
#include "io/file_attributes.h"
#include "io/file_format_exception.h"
#include "io/file_info.h"
#include "io/file_load_exception.h"
#include "io/file_not_found_exception.h"
#include "io/file_permissions.h"
#include "io/file_system_info.h"
#include "io/io_exception.h"
#include "io/path.h"
#include "io/path_too_long_exception.h"
#include "io/search_option.h"
#include "io/stream_reader.h"
#include "io/stream_writer.h"
#include "io/string_reader.h"
#include "io/string_writer.h"
#include "io/text_reader.h"
#include "io/text_writer.h"
#include "media/system_sound.h"
#include "media/system_sounds.h"
#include "net/cookie_exception.h"
#include "net/dns.h"
#include "net/dns_end_point.h"
#include "net/end_point.h"
#include "net/ip_address.h"
#include "net/ip_end_point.h"
#include "net/ip_host_entry.h"
#include "net/network_credential.h"
#include "net/protocol_violation_exception.h"
#include "net/socket_address.h"
#include "net/web_exception.h"
#include "net/sockets/address_family.h"
#include "net/sockets/io_control_code.h"
#include "net/sockets/ip_packet_information.h"
#include "net/sockets/ip_protection_level.h"
#include "net/sockets/ip_v6_multicast_option.h"
#include "net/sockets/linger_option.h"
#include "net/sockets/multicast_option.h"
#include "net/sockets/network_stream.h"
#include "net/sockets/protocol_family.h"
#include "net/sockets/protocol_type.h"
#include "net/sockets/select_mode.h"
#include "net/sockets/send_packets_element.h"
#include "net/sockets/socket.h"
#include "net/sockets/socket_async_event_args.h"
#include "net/sockets/socket_async_operation.h"
#include "net/sockets/socket_error.h"
#include "net/sockets/socket_exception.h"
#include "net/sockets/socket_flags.h"
#include "net/sockets/socket_information.h"
#include "net/sockets/socket_information_options.h"
#include "net/sockets/socket_option_level.h"
#include "net/sockets/socket_option_name.h"
#include "net/sockets/socket_shutdown.h"
#include "net/sockets/socket_type.h"
#include "net/sockets/tcp_client.h"
#include "net/sockets/tcp_listener.h"
#include "net/sockets/transmit_file_options.h"
#include "net/sockets/udp_client.h"
#include "net/sockets/socket_shutdown.h"
#include "net/sockets/socket_type.h"
#include "net/sockets/tcp_client.h"
#include "net/sockets/tcp_listener.h"
#include "net/sockets/transmit_file_options.h"
#include "net/sockets/udp_client.h"
#include "reflection/assembly.h"
#include "reflection/assembly_company_attribute.h"
#include "reflection/assembly_configuration_attribute.h"
#include "reflection/assembly_copyright_attribute.h"
#include "reflection/assembly_culture_attribute.h"
#include "reflection/assembly_description_attribute.h"
#include "reflection/assembly_file_version_attribute.h"
#include "reflection/assembly_guid_attribute.h"
#include "reflection/assembly_identifier_attribute.h"
#include "reflection/assembly_info.h"
#include "reflection/assembly_name_attribute.h"
#include "reflection/assembly_product_attribute.h"
#include "reflection/assembly_title_attribute.h"
#include "reflection/assembly_trademark_attribute.h"
#include "reflection/assembly_version_attribute.h"
#include "security/secure_string.h"
#include "security/security_exception.h"
#include "speech/synthesis/prompt.h"
#include "speech/synthesis/prompt_event_args.h"
#include "speech/synthesis/speak_completed_event_args.h"
#include "speech/synthesis/speak_completed_event_handler.h"
#include "speech/synthesis/speak_started_event_args.h"
#include "speech/synthesis/speak_started_event_handler.h"
#include "speech/synthesis/speech_synthesizer.h"
#include "speech/synthesis/state_changed_event_args.h"
#include "speech/synthesis/state_changed_event_handler.h"
#include "speech/synthesis/synthesizer_state.h"
#include "threading/abandoned_mutex_exception.h"
#include "threading/auto_reset_event.h"
#include "threading/barrier.h"
#include "threading/barrier_post_phase_exception.h"
#include "threading/cancellation_token.h"
#include "threading/cancellation_token_registration.h"
#include "threading/cancellation_token_source.h"
#include "threading/countdown_event.h"
#include "threading/event_reset_mode.h"
#include "threading/event_wait_handle.h"
#include "threading/interlocked.h"
#include "threading/jthread.h"
#include "threading/lock_guard.h"
#include "threading/lock_recursion_exception.h"
#include "threading/manual_reset_event.h"
#include "threading/monitor.h"
#include "threading/mutex.h"
#include "threading/parameterized_thread_start.h"
#include "threading/registered_wait_handle.h"
#include "threading/semaphore.h"
#include "threading/semaphore_full_exception.h"
#include "threading/spin_lock.h"
#include "threading/synchronization_lock_exception.h"
#include "threading/thread.h"
#include "threading/thread_abort_exception.h"
#include "threading/thread_interrupted_exception.h"
#include "threading/thread_local_object.h"
#include "threading/thread_pool.h"
#include "threading/thread_priority.h"
#include "threading/thread_start.h"
#include "threading/thread_state.h"
#include "threading/thread_state_exception.h"
#include "threading/timeout.h"
#include "threading/timer.h"
#include "threading/timer_callback.h"
#include "threading/wait_callback.h"
#include "threading/wait_handle.h"
#include "threading/wait_handle_cannot_be_opened_exception.h"
#include "threading/wait_or_timer_callback.h"
#include "timers/elapsed_event_args.h"
#include "timers/elapsed_event_handler.h"
#include "timers/timer.h"
#include "web/css/css_reader.h"
#include "web/css/css_writer.h"
#include "web/css/property.h"
#include "web/css/property_map.h"
#include "web/css/selector.h"
#include "web/css/selector_map.h"
#include "abstract.h"
#include "abstract_object.h"
#include "action.h"
#include "add_last_arg_to_command.h"
#include "any_object.h"
#include "architecture_id.h"
#include "argument_exception.h"
#include "argument_null_exception.h"
#include "argument_out_of_range_exception.h"
#include "arithmetic_exception.h"
#include "as.h"
#include "async_callback.h"
#include "attribute.h"
#include "availability_versions.h"
#include "background_color.h"
#include "beep.h"
#include "bit_converter.h"
#include "block_scope.h"
#include "boolean.h"
#include "boolean_object.h"
#include "box.h"
#include "box_char.h"
#include "box_floating_point.h"
#include "box_integer.h"
#include "boxing.h"
#include "build_type.h"
#include "byte.h"
#include "byte_object.h"
#include "call_once.h"
#include "cdebug.h"
#include "char.h"
#include "char16.h"
#include "char16_object.h"
#include "char32.h"
#include "char32_object.h"
#include "char8.h"
#include "char8_object.h"
#include "char_object.h"
#include "cnull.h"
#include "compiler.h"
#include "compiler_id.h"
#include "console.h"
#include "console_cancel_event_args.h"
#include "console_cancel_event_handler.h"
#include "console_color.h"
#include "console_key.h"
#include "console_key_info.h"
#include "console_modifiers.h"
#include "console_special_key.h"
#include "const_object_ref.h"
#include "convert.h"
#include "convert_pointer.h"
#include "convert_string.h"
#include "core_export.h"
#include "cpp_language.h"
#include "ctrace.h"
#include "date_time.h"
#include "date_time_kind.h"
#include "day_of_week.h"
#include "debugstreambuf.h"
#include "decimal.h"
#include "decimal_object.h"
#include "delegate.h"
#include "delete_ptr.h"
#include "delete_sptr.h"
#include "delete_uptr.h"
#include "distribution.h"
#include "divided_by_zero_exception.h"
#include "domain_exception.h"
#include "double.h"
#include "double_object.h"
#include "enum.h"
#include "enum_attribute.h"
#include "enum_class.h"
#include "enum_collection.h"
#include "enum_object.h"
#include "enum_register.h"
#include "enum_set_attribute.h"
#include "enum_struct.h"
#include "environment.h"
#include "environment_variable_target.h"
#include "event.h"
#include "event_args.h"
#include "event_handler.h"
#include "exit_mode.h"
#include "exit_status.h"
#include "flags_attribute.h"
#include "foreground_color.h"
#include "format_exception.h"
#include "func.h"
#include "generic_stream_output.h"
#include "get_err_rdbuf.h"
#include "get_in_rdbuf.h"
#include "get_out_rdbuf.h"
#include "guid.h"
#include "hash_code.h"
#include "iasync_result.h"
#include "iclonable.h"
#include "icomparable.h"
#include "iequatable.h"
#include "iformatable.h"
#include "index_out_of_range_exception.h"
#include "int16.h"
#include "int16_object.h"
#include "int32.h"
#include "int32_object.h"
#include "int64.h"
#include "int64_object.h"
#include "interface.h"
#include "intptr.h"
#include "intptr_object.h"
#include "invalid_cast_exception.h"
#include "invalid_operation_exception.h"
#include "invalid_program_exception.h"
#include "iobservable.h"
#include "iobserver.h"
#include "iprogress.h"
#include "is.h"
#include "keywords.h"
#include "language_id.h"
#include "length_exception.h"
#include "literals.h"
#include "lock.h"
#include "make_any_object.h"
#include "math.h"
#include "memory_information.h"
#include "month_of_year.h"
#include "nameof.h"
#include "new_ptr.h"
#include "new_sptr.h"
#include "new_uptr.h"
#include "not_finite_number_exception.h"
#include "not_implemented_exception.h"
#include "not_supported_exception.h"
#include "null.h"
#include "null_pointer_exception.h"
#include "number_styles.h"
#include "object.h"
#include "object_ref.h"
#include "object_closed_exception.h"
#include "operating_system.h"
#include "operation_canceled_exception.h"
#include "overflow_exception.h"
#include "overload.h"
#include "parse.h"
#include "platform_id.h"
#include "platform_not_supported_exception.h"
#include "predicate.h"
#include "processor.h"
#include "program_exit_event_args.h"
#include "program_exit_event_handler.h"
#include "ptr.h"
#include "ptrdiff.h"
#include "random.h"
#include "register_any_stringer.h"
#include "reset_color.h"
#include "sbyte.h"
#include "sbyte_object.h"
#include "scope_exit.h"
#include "self.h"
#include "signal.h"
#include "signal_cancel_event_args.h"
#include "signal_cancel_event_handler.h"
#include "single.h"
#include "single_object.h"
#include "size.h"
#include "size_object.h"
#include "slong.h"
#include "slong_object.h"
#include "sptr.h"
#include "startup.h"
#include "static.h"
#include "string_comparison.h"
#include "string_split_options.h"
#include "system_exception.h"
#include "target_id.h"
#include "target_type.h"
#include "tick.h"
#include "ticks.h"
#include "timeout_exception.h"
#include "time_span.h"
#include "time_zone_info.h"
#include "time_zone_not_found_exception.h"
#include "to_string.h"
#include "toolkit.h"
#include "tracestreambuf.h"
#include "translator.h"
#include "type.h"
#include "type_object.h"
#include "typeof.h"
#include "types.h"
#include "uint16.h"
#include "uint16_object.h"
#include "uint32.h"
#include "uint32_object.h"
#include "uint64.h"
#include "uint64_object.h"
#include "uintptr.h"
#include "uintptr_object.h"
#include "ulong.h"
#include "ulong_object.h"
#include "unauthorized_access_exception.h"
#include "unboxing.h"
#include "underflow_exception.h"
#include "unregister_any_stringer.h"
#include "unused.h"
#include "uptr.h"
#include "uri.h"
#include "uri_components.h"
#include "uri_format.h"
#include "uri_format_exception.h"
#include "uri_host_name_type.h"
#include "uri_kind.h"
#include "uri_partial.h"
#include "uri_template_match_exception.h"
#include "using.h"
#include "ustring.h"
#include "va_args_comma.h"
#include "version.h"
#include "wchar.h"
#include "wchar_object.h"
#include "wptr.h"
#include "xml_syntax_exception.h"
#include "xtd_namespace_aliases.h"
