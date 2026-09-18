	push {r4, lr}
	ldr r1, _080BFA3C @ =0x000010F0
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080BFA48
	ldr r1, _080BFA40 @ =Entity571D_Update
	ldr r2, _080BFA44 @ =Entity571D_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity571D_Init
	cmp r0, #0
	bge _080BFA48
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080BFA4A
	.align 2, 0
_080BFA3C: .4byte 0x000010F0
_080BFA40: .4byte Entity571D_Update
_080BFA44: .4byte Entity571D_Destroy
_080BFA48:
	adds r0, r4, #0
_080BFA4A:
	pop {r4}
	pop {r1}
	bx r1
