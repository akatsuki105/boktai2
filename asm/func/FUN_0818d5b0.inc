	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r2, _0818D5D8 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818D5DC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818D5DE
	.align 2, 0
_0818D5D8: .4byte 0x0000046C
_0818D5DC:
	movs r0, #0
_0818D5DE:
	cmp r0, #0
	beq _0818D69A
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #1
	ldr r4, _0818D744 @ =0x0000046D
	adds r0, r7, r4
	movs r3, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r3, [r0]
	subs r4, #0xe1
	adds r4, r7, r4
	str r4, [sp, #0x10]
	ldrh r0, [r4]
	strh r0, [r7, #0xa]
	movs r6, #0x20
	ldr r0, _0818D748 @ =0x00000474
	adds r2, r7, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0818D74C @ =0x00000F2C
	adds r4, r5, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r3, [r0]
	subs r2, #6
	adds r0, r7, r2
	strh r3, [r0]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _0818D750 @ =0xFFFFF818
	adds r1, r3, #0
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _0818D754 @ =0x0000FFFF
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0819014c
	ldr r0, _0818D758 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818D75C @ =0xFFFF7FFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	movs r1, #2
	movs r2, #6
	movs r3, #1
	bl FUN_0819328c
_0818D69A:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #6
	movs r2, #6
	bl FUN_0818fdd8
	adds r0, r5, #0
	bl FUN_0818f008
	movs r0, #0x10
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0818D6C0
	b _0818D7E8
_0818D6C0:
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r1, r0
	str r1, [r2]
	ldr r3, _0818D74C @ =0x00000F2C
	adds r2, r5, r3
	movs r1, #0x11
	rsbs r1, r1, #0
	ldrh r0, [r2]
	ands r1, r0
	movs r4, #0
	mov r8, r4
	movs r0, #0
	mov sb, r0
	strh r1, [r2]
	adds r0, r7, #0
	bl FUN_0818e6fc
	add r2, sp, #8
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _0818D760 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _0818D764 @ =0x00000D4F
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	movs r2, #0xed
	lsls r2, r2, #4
	adds r0, r5, r2
	mov r3, sb
	strh r3, [r0]
	ldrb r1, [r1]
	ldrb r0, [r7, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818D76C
	ldr r4, _0818D768 @ =0xFFFFFF00
	adds r1, r1, r4
	b _0818D77A
	.align 2, 0
_0818D744: .4byte 0x0000046D
_0818D748: .4byte 0x00000474
_0818D74C: .4byte 0x00000F2C
_0818D750: .4byte 0xFFFFF818
_0818D754: .4byte 0x0000FFFF
_0818D758: .4byte 0x000003E5
_0818D75C: .4byte 0xFFFF7FFF
_0818D760: .4byte 0x000004A4
_0818D764: .4byte 0x00000D4F
_0818D768: .4byte 0xFFFFFF00
_0818D76C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818D77A
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818D77A:
	cmp r1, #0
	bge _0818D780
	rsbs r1, r1, #0
_0818D780:
	cmp r1, #0x20
	ble _0818D7B4
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818D7AC @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _0818D7B0 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r7, r3
	str r1, [r0]
	adds r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	b _0818D7F2
	.align 2, 0
_0818D7AC: .4byte 0x00000469
_0818D7B0: .4byte 0x0000046A
_0818D7B4:
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818D7DC @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _0818D7E0 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	ldr r2, _0818D7E4 @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _0818D7F2
	.align 2, 0
_0818D7DC: .4byte 0x00000469
_0818D7E0: .4byte 0x0000046A
_0818D7E4: .4byte 0x00000484
_0818D7E8:
	ldr r4, _0818D800 @ =0x00000484
	adds r1, r7, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818D7F2:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818D800: .4byte 0x00000484
