	push {lr}
	adds r2, r0, #0
	ldr r0, _080DD740 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080DD73A
	ldr r0, [r2, #0x60]
	cmp r0, #0
	bne _080DD73A
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldr r3, _080DD744 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _080DD748 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _080DD74C @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	adds r1, #9
	bl Mod
	cmp r0, #0
	bne _080DD73A
	ldr r0, _080DD750 @ =0x00000339
	bl PlaySound_082406e0
_080DD73A:
	pop {r0}
	bx r0
	.align 2, 0
_080DD740: .4byte 0x030047A4
_080DD744: .4byte 0x030046B8
_080DD748: .4byte 0x000003FF
_080DD74C: .4byte 0x0203B400
_080DD750: .4byte 0x00000339
