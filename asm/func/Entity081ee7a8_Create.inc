	push {r4, lr}
	ldr r0, _081EE7DC @ =0x030001D0
	ldr r0, [r0]
	cmp r0, #0
	bne _081EE7EE
	ldr r1, _081EE7E0 @ =0x0000151C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EE7EC
	ldr r1, _081EE7E4 @ =Entity081ee7a8_Update
	ldr r2, _081EE7E8 @ =Entity081ee7a8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081ee7a8_Init
	cmp r0, #0
	bge _081EE7EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EE7EE
	.align 2, 0
_081EE7DC: .4byte 0x030001D0
_081EE7E0: .4byte 0x0000151C
_081EE7E4: .4byte Entity081ee7a8_Update
_081EE7E8: .4byte Entity081ee7a8_Destroy
_081EE7EC:
	adds r0, r4, #0
_081EE7EE:
	pop {r4}
	pop {r1}
	bx r1
