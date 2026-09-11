	push {r4, lr}
	ldr r1, _080B4804 @ =0x000005F4
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B4810
	ldr r1, _080B4808 @ =Entity7F5E_Update
	ldr r2, _080B480C @ =Entity7F5E_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity7F5E_Init
	cmp r0, #0
	bge _080B4810
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B4812
	.align 2, 0
_080B4804: .4byte 0x000005F4
_080B4808: .4byte Entity7F5E_Update
_080B480C: .4byte Entity7F5E_Destroy
_080B4810:
	adds r0, r4, #0
_080B4812:
	pop {r4}
	pop {r1}
	bx r1
