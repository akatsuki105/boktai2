	push {r4, lr}
	movs r0, #0x28
	bl FUN_08243648
	adds r4, r0, #0
	ldr r0, _082410DC @ =gSystemSaveData
	ldr r1, [r0]
	movs r0, #0
	adds r2, r4, #0
	bl FUN_08243988
	adds r4, #8
	cmp r0, r4
	bne _082410E0
	movs r0, #1
	b _082410E2
	.align 2, 0
_082410DC: .4byte gSystemSaveData
_082410E0:
	movs r0, #0
_082410E2:
	pop {r4}
	pop {r1}
	bx r1
