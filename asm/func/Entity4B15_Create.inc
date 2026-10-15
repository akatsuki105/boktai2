	push {r4, lr}
	ldr r0, _0801A08C @ =0x03000090
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A09A
	movs r1, #0x82
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801A098
	ldr r1, _0801A090 @ =Entity4B15_Update
	ldr r2, _0801A094 @ =Entity4B15_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity4B15_Init
	cmp r0, #0
	bge _0801A098
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801A09A
	.align 2, 0
_0801A08C: .4byte 0x03000090
_0801A090: .4byte Entity4B15_Update
_0801A094: .4byte Entity4B15_Destroy
_0801A098:
	adds r0, r4, #0
_0801A09A:
	pop {r4}
	pop {r1}
	bx r1
