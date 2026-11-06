	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081F7396:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F73A6
	movs r0, #1
	b _081F73A8
_081F73A6:
	movs r0, #0
_081F73A8:
	cmp r0, #0
	beq _081F73C2
	ldr r0, _081F73D4 @ =0x000006EC
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	adds r0, r4, #0
	bl Entity081f73ec_RemoveSprites
	adds r0, r4, #0
	bl Entity081f73ec_UnregisterHurtboxes
_081F73C2:
	adds r5, #1
	cmp r5, #0
	ble _081F7396
	ldr r1, _081F73D8 @ =0x030001FC
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081F73D4: .4byte 0x000006EC
_081F73D8: .4byte 0x030001FC
