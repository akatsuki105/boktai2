	push {r4, r5, lr}
	ldr r3, _082326E8 @ =0x030046A4
	ldr r2, [r3]
	cmp r2, #0
	bne _082326EC
	movs r0, #0
	b _0823272C
	.align 2, 0
_082326E8: .4byte 0x030046A4
_082326EC:
	movs r0, #0
	str r0, [r2, #4]
	str r0, [r2, #8]
	str r0, [r2, #0xc]
	str r0, [r2, #0x10]
	str r0, [r2, #0x18]
	ldr r1, _08232734 @ =0x030046B0
	str r0, [r1]
	strh r0, [r2]
	movs r4, #0
	adds r5, r3, #0
_08232702:
	movs r0, #0x2c
	adds r1, r4, #0
	muls r1, r0, r1
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, [r5]
	adds r0, r0, r1
	bl FUN_08234bd8
	ldr r1, [r5]
	lsls r0, r4, #2
	ldr r2, _08232738 @ =0x00000D24
	adds r1, r1, r2
	adds r1, r1, r0
	movs r0, #0
	str r0, [r1]
	adds r4, #1
	cmp r4, #0x3f
	ble _08232702
	movs r0, #1
_0823272C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08232734: .4byte 0x030046B0
_08232738: .4byte 0x00000D24
