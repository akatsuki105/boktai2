	push {r4, lr}
	ldr r0, _080604A8 @ =0x03000134
	ldr r4, [r0]
	cmp r4, #0
	bne _080604B4
	movs r1, #0xe9
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080604B4
	ldr r1, _080604AC @ =Entity08060470_Update
	ldr r2, _080604B0 @ =Entity08060470_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08060470_Init
	cmp r0, #0
	bge _080604B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080604B6
	.align 2, 0
_080604A8: .4byte 0x03000134
_080604AC: .4byte Entity08060470_Update
_080604B0: .4byte Entity08060470_Destroy
_080604B4:
	adds r0, r4, #0
_080604B6:
	pop {r4}
	pop {r1}
	bx r1
