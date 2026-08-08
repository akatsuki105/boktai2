	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	ldr r1, _082109E4 @ =0x00005EBF
	ldr r0, _082109E8 @ =0x0000CB05
	bl FUN_082310cc
	adds r3, r0, #0
	adds r1, r7, #0
	adds r1, #0x28
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r2, r4, r6}
	stm r1!, {r2, r4, r6}
	ldm r0!, {r5, r6}
	stm r1!, {r5, r6}
	movs r0, #0x28
	adds r0, r0, r7
	mov sb, r0
	adds r1, r3, #0
	bl FUN_0822f284
	add r5, sp, #0x14
	movs r4, #0
	strh r4, [r5]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	adds r0, r7, #0
	adds r0, #0x48
	str r4, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r2, #0x3c
	mov sl, r2
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sb
	movs r2, #0x19
	movs r3, #0x30
	bl FUN_0822f3fc
	strh r4, [r5]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	adds r0, r7, #0
	adds r0, #0xa8
	str r4, [sp]
	movs r3, #2
	str r3, [sp, #4]
	mov r6, sl
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sb
	movs r2, #0x1d
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r0, #0xf0
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r0]
	ldr r1, _082109EC @ =0x00000C68
	adds r6, r7, r1
	ldr r2, _082109F0 @ =0x04000008
	adds r1, r6, #0
	bl CpuSet
	mov r2, r8
	str r6, [r2]
	strh r4, [r5]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r7, r3
	str r4, [sp]
	movs r6, #2
	str r6, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sb
	movs r2, #0xd
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	movs r0, #0xa0
	strh r0, [r5]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	strh r4, [r5, #6]
	movs r3, #0xd2
	lsls r3, r3, #2
	adds r0, r7, r3
	str r4, [sp]
	movs r1, #2
	str r1, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sb
	movs r2, #0xd
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r3, #0xd4
	lsls r3, r3, #2
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	strh r4, [r5]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	movs r6, #0xea
	lsls r6, r6, #2
	adds r0, r7, r6
	str r4, [sp]
	movs r1, #2
	str r1, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sb
	movs r2, #0x22
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r3, #0x81
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	mov r6, sl
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sb
	movs r2, #0x23
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r1, _082109F4 @ =0x00005D04
	ldr r0, _082109E8 @ =0x0000CB05
	bl FUN_082310cc
	adds r3, r0, #0
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r0, r7
	mov r8, r0
	mov r2, r8
	adds r1, r3, #0
	ldm r1!, {r0, r4, r6}
	stm r2!, {r0, r4, r6}
	ldm r1!, {r0, r4, r6}
	stm r2!, {r0, r4, r6}
	ldm r1!, {r4, r6}
	stm r2!, {r4, r6}
	mov r0, r8
	adds r1, r3, #0
	bl FUN_0822f284
	movs r0, #0x91
	lsls r0, r0, #3
	adds r4, r7, r0
	movs r1, #0
	mov r2, sp
	adds r2, #0x1c
	str r2, [sp, #0x28]
	mov r3, sb
	str r3, [sp, #0x2c]
	add r5, sp, #0x14
	mov r8, r5
	mov sb, r1
_082108EE:
	lsls r0, r1, #1
	adds r6, r1, #1
	str r6, [sp, #0x24]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x18
	mov sl, r0
	movs r5, #0x70
	movs r6, #4
_08210900:
	add r0, sp, #0x14
	strh r5, [r0]
	mov r1, sl
	mov r0, r8
	strh r1, [r0, #2]
	mov r2, sb
	strh r2, [r0, #4]
	strh r2, [r0, #6]
	mov r3, sb
	str r3, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r2, r8
	str r2, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r7, r3
	movs r2, #0x1d
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
	adds r4, #0x60
	adds r5, #0x18
	subs r6, #1
	cmp r6, #0
	bge _08210900
	ldr r1, [sp, #0x24]
	cmp r1, #3
	ble _082108EE
	adds r0, r7, #0
	bl FUN_08210bb0
	movs r4, #0
	movs r1, #0x80
	add r0, sp, #0x1c
	strh r4, [r0]
	ldr r5, [sp, #0x28]
	strh r1, [r5, #2]
	strh r4, [r5, #4]
	ldr r6, _082109F8 @ =0x00000C08
	adds r0, r7, r6
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r1, r7, r2
	str r4, [sp]
	movs r3, #2
	str r3, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xc]
	movs r2, #0x1d
	movs r3, #0x31
	bl FUN_0822f3fc
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	add r1, sp, #0x14
	ldr r2, _082109FC @ =0x05000002
	bl CpuSet
	movs r0, #0x84
	lsls r0, r0, #1
	adds r4, r7, r0
	movs r6, #4
_08210990:
	movs r5, #0
	str r5, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x14
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x2c]
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r6, #1
	cmp r6, #0
	bge _08210990
	adds r0, r7, #0
	bl FUN_08210610
	movs r1, #0x36
	movs r2, #0x48
	add r0, sp, #0x14
	strh r1, [r0]
	mov r3, sp
	strh r2, [r3, #0x16]
	strh r5, [r3, #0x18]
	ldr r5, _08210A00 @ =0x00000CD4
	adds r4, r7, r5
	ldr r1, _08210A04 @ =0x0000DE23
	adds r0, r4, #0
	movs r2, #0x10
	add r3, sp, #0x14
	bl FUN_08055e34
	cmp r0, #0
	bge _08210A08
	movs r0, #1
	rsbs r0, r0, #0
	b _08210A7E
	.align 2, 0
_082109E4: .4byte 0x00005EBF
_082109E8: .4byte 0x0000CB05
_082109EC: .4byte 0x00000C68
_082109F0: .4byte 0x04000008
_082109F4: .4byte 0x00005D04
_082109F8: .4byte 0x00000C08
_082109FC: .4byte 0x05000002
_08210A00: .4byte 0x00000CD4
_08210A04: .4byte 0x0000DE23
_08210A08:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08055f5c
	movs r6, #0xce
	lsls r6, r6, #4
	adds r5, r7, r6
	ldr r0, [r5, #0x68]
	ldr r1, _08210A90 @ =0x00000D68
	adds r4, r7, r1
	ldr r2, _08210A94 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	str r4, [r5, #0x68]
	ldr r2, _08210A98 @ =0x00000CB8
	adds r5, r7, r2
	ldr r1, _08210A9C @ =0x00001C1B
	adds r0, r5, #0
	bl FUN_0822b16c
	ldr r3, _08210AA0 @ =0x00000C8C
	adds r4, r7, r3
	ldr r2, _08210AA4 @ =0x00000212
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a470
	movs r1, #5
	strh r1, [r4, #0x10]
	ldr r4, _08210AA8 @ =0x00000C93
	adds r2, r7, r4
	movs r1, #3
	strb r1, [r2]
	movs r5, #0xd6
	lsls r5, r5, #4
	adds r3, r7, r5
	ldr r1, [r3]
	ldrh r2, [r1]
	subs r6, #0x38
	adds r1, r7, r6
	strh r2, [r1]
	ldr r1, [r3]
	ldrh r2, [r1, #2]
	adds r4, #0x17
	adds r1, r7, r4
	strh r2, [r1]
	ldr r1, [r3]
	ldrh r2, [r1, #4]
	subs r5, #0xb4
	adds r1, r7, r5
	strh r2, [r1]
	subs r6, #0x14
	adds r1, r7, r6
	movs r2, #0x40
	strb r2, [r1]
	ldr r3, _08210AAC @ =0x00000C95
	adds r1, r7, r3
	strb r2, [r1]
_08210A7E:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08210A90: .4byte 0x00000D68
_08210A94: .4byte 0x04000008
_08210A98: .4byte 0x00000CB8
_08210A9C: .4byte 0x00001C1B
_08210AA0: .4byte 0x00000C8C
_08210AA4: .4byte 0x00000212
_08210AA8: .4byte 0x00000C93
_08210AAC: .4byte 0x00000C95
