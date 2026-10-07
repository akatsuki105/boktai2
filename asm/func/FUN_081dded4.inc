	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x30]
	movs r1, #0
	strh r0, [r4, #0x32]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	bl FUN_081ddc04
	movs r3, #0
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, _081DDF38 @ =0x000003FF
	ldr r1, _081DDF3C @ =0x03004510
_081DDEF4:
	strh r2, [r0]
	strh r2, [r0, #8]
	strh r2, [r0, #0x10]
	strh r5, [r1]
	adds r0, #2
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _081DDEF4
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081dde98
	ldr r2, _081DDF40 @ =0x030046B8
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r0, _081DDF38 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DDF38: .4byte 0x000003FF
_081DDF3C: .4byte 0x03004510
_081DDF40: .4byte 0x030046B8
