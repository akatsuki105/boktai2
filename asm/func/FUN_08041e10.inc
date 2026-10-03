	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r1, #0
	movs r0, #0x43
	movs r1, #1
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _08041E2C
	adds r0, r7, #0
	bl FUN_080410cc
_08041E2C:
	adds r0, r7, #0
	adds r0, #0x61
	ldrb r1, [r0]
	ldr r2, _08041EA4 @ =0x00000215
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0x43
	movs r1, #1
	bl VM_GetNamedArgValue
	ldr r3, _08041EA8 @ =0x00000216
	adds r1, r7, r3
	strb r0, [r1]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08041EB0
	bl VM_GetValue
	ldr r1, _08041EAC @ =0x000001EF
	adds r1, r1, r7
	mov r8, r1
	strb r0, [r1]
	bl VM_GetValue
	movs r2, #0x83
	lsls r2, r2, #2
	adds r4, r7, r2
	strh r0, [r4]
	bl VM_GetValue
	movs r3, #0x84
	lsls r3, r3, #2
	adds r6, r7, r3
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0x5c
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r7, r2
	mov r3, r8
	ldrb r2, [r3]
	ldrb r3, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r5, #0
	bl Mover_SetPath
	adds r0, r7, #0
	adds r0, #0x64
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r1, [r1]
	ldrb r2, [r6]
	bl FUN_08234f80
	b _08041EB8
	.align 2, 0
_08041EA4: .4byte 0x00000215
_08041EA8: .4byte 0x00000216
_08041EAC: .4byte 0x000001EF
_08041EB0:
	ldr r3, _08041EF0 @ =0x000001EF
	adds r1, r7, r3
	movs r0, #0xff
	strb r0, [r1]
_08041EB8:
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08041EFC
	ldr r0, _08041EF4 @ =0x000001ED
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	bl VM_GetValue
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetValue
	ldr r3, _08041EF8 @ =0x0000023E
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0x90
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	b _08041F10
	.align 2, 0
_08041EF0: .4byte 0x000001EF
_08041EF4: .4byte 0x000001ED
_08041EF8: .4byte 0x0000023E
_08041EFC:
	ldr r3, _08041F54 @ =0x000001ED
	adds r1, r7, r3
	strb r0, [r1]
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	str r0, [r2]
	str r1, [r2, #4]
_08041F10:
	movs r0, #0x54
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _08041F64
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	bl VM_GetValue
	ldr r3, _08041F58 @ =0x00000231
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetValue
	ldr r2, _08041F5C @ =0x00000232
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetValue
	ldr r3, _08041F60 @ =0x00000233
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetValue
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	strb r0, [r1]
	b _08041F8A
	.align 2, 0
_08041F54: .4byte 0x000001ED
_08041F58: .4byte 0x00000231
_08041F5C: .4byte 0x00000232
_08041F60: .4byte 0x00000233
_08041F64:
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _08041FBC @ =0x00000231
	adds r1, r7, r0
	movs r0, #9
	strb r0, [r1]
	ldr r1, _08041FC0 @ =0x00000232
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #3
	adds r1, r7, r3
	movs r0, #0x15
	strb r0, [r1]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
_08041F8A:
	movs r0, #0x62
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _08041FC8
	bl VM_GetValue
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetValue
	ldr r3, _08041FC4 @ =0x000001E9
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetValue
	movs r2, #0xf5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	b _08041FE0
	.align 2, 0
_08041FBC: .4byte 0x00000231
_08041FC0: .4byte 0x00000232
_08041FC4: .4byte 0x000001E9
_08041FC8:
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _08042010 @ =0x000001E9
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xf5
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r2, [r0]
_08041FE0:
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08042014
	bl VM_GetValue
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	bl VM_GetValue
	movs r3, #0x87
	lsls r3, r3, #2
	adds r1, r7, r3
	str r0, [r1]
	bl VM_GetValue
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r7, r2
	b _08042030
	.align 2, 0
_08042010: .4byte 0x000001E9
_08042014:
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r0]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r7, r2
	str r1, [r0]
	subs r3, #8
	adds r1, r7, r3
	movs r0, #0x80
	lsls r0, r0, #2
_08042030:
	str r0, [r1]
	movs r0, #0x48
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804206C
	bl VM_GetValue
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetValue
	ldr r3, _08042060 @ =0x00000239
	adds r1, r7, r3
	strb r0, [r1]
	ldr r0, _08042064 @ =0x0000023A
	adds r1, r7, r0
	movs r0, #4
	strb r0, [r1]
	ldr r2, _08042068 @ =0x0000023B
	adds r1, r7, r2
	b _08042088
	.align 2, 0
_08042060: .4byte 0x00000239
_08042064: .4byte 0x0000023A
_08042068: .4byte 0x0000023B
_0804206C:
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #6
	strb r1, [r0]
	ldr r2, _080420EC @ =0x00000239
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #2
	adds r1, r7, r3
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080420F0 @ =0x0000023B
	adds r1, r7, r0
_08042088:
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #0x42
	movs r1, #4
	bl VM_GetNamedArgValue
	ldr r2, _080420F4 @ =0x0000023A
	adds r1, r7, r2
	strb r0, [r1]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [r7, #0x40]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080420F8
	bl VM_GetValue
	adds r4, r0, #0
	bl VM_GetValue
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r4, [r1]
	movs r2, #0xf9
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	adds r3, #4
	adds r1, r7, r3
	str r4, [r1]
	adds r2, #6
	adds r1, r7, r2
	str r0, [r1]
	adds r3, #8
	adds r2, r7, r3
	adds r1, r4, #0
	muls r1, r4, r1
	str r1, [r2]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	b _0804212C
	.align 2, 0
_080420EC: .4byte 0x00000239
_080420F0: .4byte 0x0000023B
_080420F4: .4byte 0x0000023A
_080420F8:
	movs r1, #0x50
	movs r2, #0x60
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strh r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	str r1, [r0]
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0xc8
	lsls r0, r0, #5
	str r0, [r1]
	adds r3, #0xc
	adds r1, r7, r3
	movs r0, #0x90
	lsls r0, r0, #6
_0804212C:
	str r0, [r1]
	movs r0, #0x4d
	movs r1, #0xa
	bl VM_GetNamedArgValue
	movs r2, #0x81
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	movs r3, #0x82
	lsls r3, r3, #2
	adds r1, r7, r3
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	str r0, [r1]
	movs r0, #0x75
	movs r1, #1
	bl VM_GetNamedArgValue
	strb r0, [r7, #0xb]
	movs r0, #0x46
	movs r1, #1
	bl VM_GetNamedArgValue
	ldr r3, _08042174 @ =0x00000212
	adds r1, r7, r3
	strb r0, [r1]
	movs r0, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08042174: .4byte 0x00000212
