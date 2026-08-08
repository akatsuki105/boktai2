	push {lr}
	ldr r2, _08064044 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08064048 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806404C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, #0xa
	ble _08064050
	movs r0, #0
	b _08064054
	.align 2, 0
_08064044: .4byte 0x030046B8
_08064048: .4byte 0x000003FF
_0806404C: .4byte 0x0203B400
_08064050:
	movs r0, #0x80
	lsls r0, r0, #0xc
_08064054:
	pop {r1}
	bx r1
