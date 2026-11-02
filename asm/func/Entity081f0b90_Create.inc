	push {r4, lr}
	ldr r0, _081F0BC4 @ =0x030001E4
	ldr r0, [r0]
	cmp r0, #0
	bne _081F0BD6
	ldr r1, _081F0BC8 @ =0x000005AC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F0BD4
	ldr r1, _081F0BCC @ =Entity081f0b90_Update
	ldr r2, _081F0BD0 @ =Entity081f0b90_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f0b90_Init
	cmp r0, #0
	bge _081F0BD4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F0BD6
	.align 2, 0
_081F0BC4: .4byte 0x030001E4
_081F0BC8: .4byte 0x000005AC
_081F0BCC: .4byte Entity081f0b90_Update
_081F0BD0: .4byte Entity081f0b90_Destroy
_081F0BD4:
	adds r0, r4, #0
_081F0BD6:
	pop {r4}
	pop {r1}
	bx r1
