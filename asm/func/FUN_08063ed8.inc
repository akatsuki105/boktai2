	push {lr}
	ldr r2, _08063EFC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08063F00 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08063F04 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, #0xa
	ble _08063F08
	movs r0, #0
	b _08063F0A
	.align 2, 0
_08063EFC: .4byte 0x030046B8
_08063F00: .4byte 0x000003FF
_08063F04: .4byte 0x0203B400
_08063F08:
	movs r0, #0xa
_08063F0A:
	pop {r1}
	bx r1
	.align 2, 0
