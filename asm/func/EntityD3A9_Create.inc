	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xb
	movs r1, #0x50
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C0D64
	ldr r1, _080C0D5C @ =EntityD3A9_Update
	ldr r2, _080C0D60 @ =EntityD3A9_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityD3A9_Init
	cmp r0, #0
	bge _080C0D64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C0D66
	.align 2, 0
_080C0D5C: .4byte EntityD3A9_Update
_080C0D60: .4byte EntityD3A9_Destroy
_080C0D64:
	adds r0, r4, #0
_080C0D66:
	pop {r4, r5}
	pop {r1}
	bx r1
