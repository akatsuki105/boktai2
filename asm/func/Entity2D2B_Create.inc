	push {r4, lr}
	ldr r0, _080085E4 @ =0x03000034
	ldr r0, [r0]
	cmp r0, #0
	bne _080085F2
	movs r0, #0xa
	movs r1, #0x60
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080085F0
	ldr r1, _080085E8 @ =Entity2D2B_Update
	ldr r2, _080085EC @ =Entity2D2B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity2D2B_Init
	cmp r0, #0
	bge _080085F0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080085F2
	.align 2, 0
_080085E4: .4byte 0x03000034
_080085E8: .4byte Entity2D2B_Update
_080085EC: .4byte Entity2D2B_Destroy
_080085F0:
	adds r0, r4, #0
_080085F2:
	pop {r4}
	pop {r1}
	bx r1
