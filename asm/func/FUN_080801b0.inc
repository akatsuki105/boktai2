	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080801E0 @ =0x000004C4
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080801EC
	ldr r1, _080801E4 @ =FUN_0807fe04
	ldr r2, _080801E8 @ =FUN_0807fe24
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08080148
	cmp r0, #0
	bge _080801EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080801EE
	.align 2, 0
_080801E0: .4byte 0x000004C4
_080801E4: .4byte FUN_0807fe04
_080801E8: .4byte FUN_0807fe24
_080801EC:
	adds r0, r4, #0
_080801EE:
	pop {r4, r5}
	pop {r1}
	bx r1
