	push {r4, lr}
	ldr r0, _081EB324 @ =0x030001C4
	ldr r0, [r0]
	cmp r0, #0
	bne _081EB336
	ldr r1, _081EB328 @ =0x00000924
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EB334
	ldr r1, _081EB32C @ =Entity081eb2f0_Update
	ldr r2, _081EB330 @ =Entity081eb2f0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081eb2f0_Init
	cmp r0, #0
	bge _081EB334
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EB336
	.align 2, 0
_081EB324: .4byte 0x030001C4
_081EB328: .4byte 0x00000924
_081EB32C: .4byte Entity081eb2f0_Update
_081EB330: .4byte Entity081eb2f0_Destroy
_081EB334:
	adds r0, r4, #0
_081EB336:
	pop {r4}
	pop {r1}
	bx r1
