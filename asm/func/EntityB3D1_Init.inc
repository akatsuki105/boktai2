	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080C0832
	bl VM_GetValue
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	b _080C083A
_080C0832:
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r1, [r0]
_080C083A:
	adds r5, r7, #0
	adds r5, #0x4c
	ldr r0, _080C08C0 @ =0x0000C046
	mov r8, r0
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetAuxSprite
	adds r4, r7, #0
	adds r4, #0x20
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r6, #0
	strh r6, [r4, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r7, #0x3c]
	strh r6, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x40
	ldr r0, _080C08C4 @ =0x0000052C
	strh r0, [r1]
	adds r5, #0x4c
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetAuxSprite
	adds r4, #0x4c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r6, [r4, #0x10]
	adds r2, r7, #0
	adds r2, #0x88
	ldr r0, [r7, #0x3c]
	ldr r1, [r7, #0x40]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0x8c
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x4e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C08E0
	bl VM_GetValue
	cmp r0, #3
	beq _080C08D0
	cmp r0, #3
	ble _080C08E0
	cmp r0, #4
	beq _080C08C8
	cmp r0, #0xa
	beq _080C08D8
	b _080C08E0
	.align 2, 0
_080C08C0: .4byte 0x0000C046
_080C08C4: .4byte 0x0000052C
_080C08C8:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #1
	b _080C08E6
_080C08D0:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #4
	b _080C08E6
_080C08D8:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #3
	b _080C08E6
_080C08E0:
	adds r1, r7, #0
	adds r1, #0xb6
	movs r0, #2
_080C08E6:
	strh r0, [r1]
	adds r5, r7, #0
	adds r5, #0xe4
	ldr r1, _080C095C @ =0x0000C046
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r4, r7, #0
	adds r4, #0xb8
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r2, r7, #0
	adds r2, #0xd4
	ldr r0, [r7, #0x3c]
	ldr r1, [r7, #0x40]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r7, #0
	adds r1, #0xd8
	ldr r2, _080C0960 @ =0xFFFFFD00
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080c05cc
	adds r0, r7, #0
	bl FUN_080bfc60
	ldr r1, _080C0964 @ =FUN_080c01a8
	adds r0, r7, #0
	bl EntityB3D1_SetState
	adds r0, r7, #0
	bl FUN_080c0770
	adds r0, r7, #0
	bl FUN_080c06e4
	adds r0, r7, #0
	bl FUN_080bffcc
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C096C
	bl VM_GetValue
	ldr r2, _080C0968 @ =0x000005B2
	adds r1, r7, r2
	b _080C0974
	.align 2, 0
_080C095C: .4byte 0x0000C046
_080C0960: .4byte 0xFFFFFD00
_080C0964: .4byte FUN_080c01a8
_080C0968: .4byte 0x000005B2
_080C096C:
	ldr r0, _080C09A0 @ =0x000005B2
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
_080C0974:
	strh r0, [r1]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C09B0
	bl VM_GetValue
	ldr r2, _080C09A4 @ =0x0000058A
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetValue
	ldr r2, _080C09A8 @ =0x0000058C
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetValue
	ldr r2, _080C09AC @ =0x0000058E
	adds r1, r7, r2
	b _080C09C8
	.align 2, 0
_080C09A0: .4byte 0x000005B2
_080C09A4: .4byte 0x0000058A
_080C09A8: .4byte 0x0000058C
_080C09AC: .4byte 0x0000058E
_080C09B0:
	ldr r0, _080C09E4 @ =0x0000058A
	adds r1, r7, r0
	movs r0, #0xb4
	strh r0, [r1]
	ldr r2, _080C09E8 @ =0x0000058C
	adds r1, r7, r2
	adds r0, #0x78
	strh r0, [r1]
	ldr r0, _080C09EC @ =0x0000058E
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #2
_080C09C8:
	strh r0, [r1]
	movs r0, #0x62
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080C09F4
	bl VM_GetValue
	ldr r2, _080C09F0 @ =0x000005A4
	adds r1, r7, r2
	str r0, [r1]
	b _080C09FA
	.align 2, 0
_080C09E4: .4byte 0x0000058A
_080C09E8: .4byte 0x0000058C
_080C09EC: .4byte 0x0000058E
_080C09F0: .4byte 0x000005A4
_080C09F4:
	ldr r2, _080C0A7C @ =0x000005A4
	adds r0, r7, r2
	str r1, [r0]
_080C09FA:
	movs r0, #0xb2
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r5, [r0]
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C0A22
	bl VM_GetValue
	ldr r2, _080C0A80 @ =0x000005AC
	adds r1, r7, r2
	str r0, [r1]
_080C0A22:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C0A50
	bl VM_GetValue
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	bl VM_GetValue
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	bl VM_GetValue
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
_080C0A50:
	ldr r0, _080C0A84 @ =0x00000594
	adds r4, r7, r0
	str r5, [r4]
	ldr r1, _080C0A88 @ =0x0000059C
	adds r0, r7, r1
	str r5, [r0]
	ldr r0, _080C0A8C @ =0x0000023E
	bl PlaySound_082406e0
	ldr r2, _080C0A90 @ =0x0000057E
	adds r0, r7, r2
	strh r5, [r0]
	str r5, [r4]
	ldr r0, _080C0A94 @ =0x03000158
	str r7, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C0A7C: .4byte 0x000005A4
_080C0A80: .4byte 0x000005AC
_080C0A84: .4byte 0x00000594
_080C0A88: .4byte 0x0000059C
_080C0A8C: .4byte 0x0000023E
_080C0A90: .4byte 0x0000057E
_080C0A94: .4byte 0x03000158
