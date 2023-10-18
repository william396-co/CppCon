// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: example.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_example_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_example_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_example_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_example_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_example_2eproto;
class SearchRequest;
struct SearchRequestDefaultTypeInternal;
extern SearchRequestDefaultTypeInternal _SearchRequest_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::SearchRequest* Arena::CreateMaybeMessage<::SearchRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class SearchRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SearchRequest) */ {
 public:
  inline SearchRequest() : SearchRequest(nullptr) {}
  ~SearchRequest() override;
  explicit PROTOBUF_CONSTEXPR SearchRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  SearchRequest(const SearchRequest& from);
  SearchRequest(SearchRequest&& from) noexcept
    : SearchRequest() {
    *this = ::std::move(from);
  }

  inline SearchRequest& operator=(const SearchRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline SearchRequest& operator=(SearchRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SearchRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const SearchRequest* internal_default_instance() {
    return reinterpret_cast<const SearchRequest*>(
               &_SearchRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SearchRequest& a, SearchRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(SearchRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SearchRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SearchRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<SearchRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const SearchRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const SearchRequest& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SearchRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SearchRequest";
  }
  protected:
  explicit SearchRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kQueryFieldNumber = 1,
    kPageNumberFieldNumber = 2,
    kResultsPerPageFieldNumber = 3,
  };
  // string query = 1;
  void clear_query();
  const std::string& query() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_query(ArgT0&& arg0, ArgT... args);
  std::string* mutable_query();
  PROTOBUF_NODISCARD std::string* release_query();
  void set_allocated_query(std::string* query);
  private:
  const std::string& _internal_query() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_query(const std::string& value);
  std::string* _internal_mutable_query();
  public:

  // int32 page_number = 2;
  void clear_page_number();
  int32_t page_number() const;
  void set_page_number(int32_t value);
  private:
  int32_t _internal_page_number() const;
  void _internal_set_page_number(int32_t value);
  public:

  // int32 results_per_page = 3;
  void clear_results_per_page();
  int32_t results_per_page() const;
  void set_results_per_page(int32_t value);
  private:
  int32_t _internal_results_per_page() const;
  void _internal_set_results_per_page(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:SearchRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr query_;
  int32_t page_number_;
  int32_t results_per_page_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_example_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SearchRequest

// string query = 1;
inline void SearchRequest::clear_query() {
  query_.ClearToEmpty();
}
inline const std::string& SearchRequest::query() const {
  // @@protoc_insertion_point(field_get:SearchRequest.query)
  return _internal_query();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void SearchRequest::set_query(ArgT0&& arg0, ArgT... args) {
 
 query_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:SearchRequest.query)
}
inline std::string* SearchRequest::mutable_query() {
  std::string* _s = _internal_mutable_query();
  // @@protoc_insertion_point(field_mutable:SearchRequest.query)
  return _s;
}
inline const std::string& SearchRequest::_internal_query() const {
  return query_.Get();
}
inline void SearchRequest::_internal_set_query(const std::string& value) {
  
  query_.Set(value, GetArenaForAllocation());
}
inline std::string* SearchRequest::_internal_mutable_query() {
  
  return query_.Mutable(GetArenaForAllocation());
}
inline std::string* SearchRequest::release_query() {
  // @@protoc_insertion_point(field_release:SearchRequest.query)
  return query_.Release();
}
inline void SearchRequest::set_allocated_query(std::string* query) {
  if (query != nullptr) {
    
  } else {
    
  }
  query_.SetAllocated(query, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (query_.IsDefault()) {
    query_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:SearchRequest.query)
}

// int32 page_number = 2;
inline void SearchRequest::clear_page_number() {
  page_number_ = 0;
}
inline int32_t SearchRequest::_internal_page_number() const {
  return page_number_;
}
inline int32_t SearchRequest::page_number() const {
  // @@protoc_insertion_point(field_get:SearchRequest.page_number)
  return _internal_page_number();
}
inline void SearchRequest::_internal_set_page_number(int32_t value) {
  
  page_number_ = value;
}
inline void SearchRequest::set_page_number(int32_t value) {
  _internal_set_page_number(value);
  // @@protoc_insertion_point(field_set:SearchRequest.page_number)
}

// int32 results_per_page = 3;
inline void SearchRequest::clear_results_per_page() {
  results_per_page_ = 0;
}
inline int32_t SearchRequest::_internal_results_per_page() const {
  return results_per_page_;
}
inline int32_t SearchRequest::results_per_page() const {
  // @@protoc_insertion_point(field_get:SearchRequest.results_per_page)
  return _internal_results_per_page();
}
inline void SearchRequest::_internal_set_results_per_page(int32_t value) {
  
  results_per_page_ = value;
}
inline void SearchRequest::set_results_per_page(int32_t value) {
  _internal_set_results_per_page(value);
  // @@protoc_insertion_point(field_set:SearchRequest.results_per_page)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_example_2eproto
