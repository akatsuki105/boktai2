	push {r4, lr}
	ldr r0, _080DF458 @ =0x03000178
	ldr r0, [r0]
	cmp r0, #0
	bne _080DF466
	movs r1, #0xbf
	lsls r1, r1, #5
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DF464
	ldr r1, _080DF45C @ =FUN_080df31c
	ldr r2, _080DF460 @ =0x080DF3B5
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080df3f4
	cmp r0, #0
	bge _080DF464
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DF466
	.align 2, 0
_080DF458: .4byte 0x03000178
_080DF45C: .4byte FUN_080df31c
_080DF460: .4byte 0x080DF3B5
_080DF464:
	adds r0, r4, #0
_080DF466:
	pop {r4}
	pop {r1}
	bx r1
