	push {r4, lr}
	ldr r0, _081F02CC @ =0x030001E0
	ldr r0, [r0]
	cmp r0, #0
	bne _081F02DE
	ldr r1, _081F02D0 @ =0x0000078C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F02DC
	ldr r1, _081F02D4 @ =Entity081f0298_Update
	ldr r2, _081F02D8 @ =Entity081f0298_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f0298_Init
	cmp r0, #0
	bge _081F02DC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F02DE
	.align 2, 0
_081F02CC: .4byte 0x030001E0
_081F02D0: .4byte 0x0000078C
_081F02D4: .4byte Entity081f0298_Update
_081F02D8: .4byte Entity081f0298_Destroy
_081F02DC:
	adds r0, r4, #0
_081F02DE:
	pop {r4}
	pop {r1}
	bx r1
