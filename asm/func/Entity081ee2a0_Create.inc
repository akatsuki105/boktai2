	push {r4, lr}
	ldr r0, _081EE2D8 @ =0x030001CC
	ldr r0, [r0]
	cmp r0, #0
	bne _081EE2E6
	movs r1, #0xd4
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EE2E4
	ldr r1, _081EE2DC @ =Entity081ee2a0_Update
	ldr r2, _081EE2E0 @ =Entity081ee2a0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081ee2a0_Init
	cmp r0, #0
	bge _081EE2E4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EE2E6
	.align 2, 0
_081EE2D8: .4byte 0x030001CC
_081EE2DC: .4byte Entity081ee2a0_Update
_081EE2E0: .4byte Entity081ee2a0_Destroy
_081EE2E4:
	adds r0, r4, #0
_081EE2E6:
	pop {r4}
	pop {r1}
	bx r1
