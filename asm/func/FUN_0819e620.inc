	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r2, [r0]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r3, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r4, _0819E650 @ =0x00000546
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819E658
	ldr r5, _0819E654 @ =0x00000EBA
	adds r0, r2, r5
	ldrh r4, [r0]
	cmp r4, #0
	bne _0819E658
	movs r1, #2
	movs r2, #8
	b _0819E74A
	.align 2, 0
_0819E650: .4byte 0x00000546
_0819E654: .4byte 0x00000EBA
_0819E658:
	ldr r5, _0819E688 @ =0x00000EB4
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _0819E710
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _0819E68C @ =0x0000FFFE
	cmp r1, r0
	bhi _0819E710
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrb r2, [r0]
	adds r1, r2, #0
	subs r1, #0xa0
	cmp r1, #0x80
	ble _0819E694
	ldr r4, _0819E690 @ =0xFFFFFE60
	adds r1, r2, r4
	b _0819E6A0
	.align 2, 0
_0819E688: .4byte 0x00000EB4
_0819E68C: .4byte 0x0000FFFE
_0819E690: .4byte 0xFFFFFE60
_0819E694:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819E6A0
	adds r1, r2, #0
	adds r1, #0x60
_0819E6A0:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819E6A8
	rsbs r0, r0, #0
_0819E6A8:
	cmp r0, #0x29
	bgt _0819E6D8
	movs r2, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #0
	strb r1, [r0]
	ldr r4, _0819E6D0 @ =0x00000469
	adds r0, r3, r4
	strb r2, [r0]
	adds r5, #2
	adds r0, r3, r5
	strb r1, [r0]
	ldr r2, _0819E6D4 @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r4, #3
	adds r1, r3, r4
	b _0819E6FA
	.align 2, 0
_0819E6D0: .4byte 0x00000469
_0819E6D4: .4byte 0x00000484
_0819E6D8:
	movs r1, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r2, #0
	strb r2, [r0]
	ldr r4, _0819E704 @ =0x00000469
	adds r0, r3, r4
	strb r1, [r0]
	adds r5, #2
	adds r0, r3, r5
	strb r1, [r0]
	ldr r1, _0819E708 @ =0x00000484
	adds r0, r3, r1
	str r2, [r0]
	ldr r2, _0819E70C @ =0x0000046C
	adds r1, r3, r2
_0819E6FA:
	movs r0, #1
	strb r0, [r1]
	movs r0, #1
	b _0819E782
	.align 2, 0
_0819E704: .4byte 0x00000469
_0819E708: .4byte 0x00000484
_0819E70C: .4byte 0x0000046C
_0819E710:
	movs r4, #0xeb
	lsls r4, r4, #4
	adds r0, r2, r4
	ldrh r1, [r0]
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r3, r5
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	blt _0819E780
	ldr r5, _0819E738 @ =0x00000EB6
	adds r0, r2, r5
	ldrh r4, [r0]
	cmp r4, #0
	bne _0819E73C
	movs r1, #2
	movs r2, #4
	b _0819E74A
	.align 2, 0
_0819E738: .4byte 0x00000EB6
_0819E73C:
	ldr r5, _0819E770 @ =0x00000EB8
	adds r0, r2, r5
	ldrh r4, [r0]
	cmp r4, #0
	bne _0819E780
	movs r1, #2
	movs r2, #6
_0819E74A:
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	strb r4, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r1, [r0]
	ldr r1, _0819E774 @ =0x0000046A
	adds r0, r3, r1
	strb r2, [r0]
	ldr r2, _0819E778 @ =0x00000484
	adds r0, r3, r2
	str r4, [r0]
	ldr r4, _0819E77C @ =0x0000046C
	adds r1, r3, r4
	movs r0, #1
	strb r0, [r1]
	b _0819E782
	.align 2, 0
_0819E770: .4byte 0x00000EB8
_0819E774: .4byte 0x0000046A
_0819E778: .4byte 0x00000484
_0819E77C: .4byte 0x0000046C
_0819E780:
	movs r0, #0
_0819E782:
	pop {r4, r5}
	pop {r1}
	bx r1
