	push {r4, lr}
	ldr r0, _081F26F0 @ =0x030001EC
	ldr r0, [r0]
	cmp r0, #0
	bne _081F2702
	ldr r1, _081F26F4 @ =0x00000B5C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F2700
	ldr r1, _081F26F8 @ =Entity081f26bc_Update
	ldr r2, _081F26FC @ =Entity081f26bc_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f26bc_Init
	cmp r0, #0
	bge _081F2700
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F2702
	.align 2, 0
_081F26F0: .4byte 0x030001EC
_081F26F4: .4byte 0x00000B5C
_081F26F8: .4byte Entity081f26bc_Update
_081F26FC: .4byte Entity081f26bc_Destroy
_081F2700:
	adds r0, r4, #0
_081F2702:
	pop {r4}
	pop {r1}
	bx r1
