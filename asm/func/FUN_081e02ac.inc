	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081E02E0 @ =0x000003EA
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _081E02C6
	ldr r0, _081E02E4 @ =0x000002A5
	bl PlaySound_082406e0
_081E02C6:
	ldr r1, _081E02E8 @ =0x000003BA
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081E02D8
	adds r0, r4, #0
	movs r1, #0
	bl Entity501B_SpinNumber
_081E02D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E02E0: .4byte 0x000003EA
_081E02E4: .4byte 0x000002A5
_081E02E8: .4byte 0x000003BA
