	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _082233A8 @ =0x00000D9C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #0x30
	orrs r0, r1
	str r0, [r2]
	mov r5, sp
	ldr r1, _082233AC @ =0x00000DB8
	adds r2, r6, r1
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082233B0
	asrs r0, r0, #8
	b _082233B6
	.align 2, 0
_082233A8: .4byte 0x00000D9C
_082233AC: .4byte 0x00000DB8
_082233B0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082233B6:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082233C8
	asrs r0, r0, #8
	b _082233CE
_082233C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082233CE:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _082233E2
	asrs r0, r0, #8
	b _082233E8
_082233E2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082233E8:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08223418 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xf0
	ble _0822341C
	movs r1, #0xf0
	mov r0, sp
	strh r1, [r0]
	b _08223426
	.align 2, 0
_08223418: .4byte 0x030047C8
_0822341C:
	cmp r0, #0
	bge _08223426
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
_08223426:
	mov r1, sp
	ldrh r0, [r1, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _08223436
	movs r0, #0xb4
	b _0822343C
_08223436:
	cmp r0, #0
	bge _0822343E
	movs r0, #0
_0822343C:
	strh r0, [r1, #2]
_0822343E:
	mov r0, sp
	ldrh r1, [r0]
	ldr r2, _08223464 @ =0x00000DB8
	adds r0, r6, r2
	movs r2, #0
	strh r1, [r0]
	mov r0, sp
	ldrh r1, [r0, #2]
	ldr r3, _08223468 @ =0x00000DBA
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _0822346C @ =0x00000DBC
	adds r0, r6, r1
	strh r2, [r0]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08223464: .4byte 0x00000DB8
_08223468: .4byte 0x00000DBA
_0822346C: .4byte 0x00000DBC
