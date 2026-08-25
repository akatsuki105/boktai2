	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080E1538 @ =0x03000180
	ldr r0, [r0]
	cmp r0, #0
	bne _080E1546
	movs r1, #0xce
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080E1544
	ldr r1, _080E153C @ =0x080E13D5
	ldr r2, _080E1540 @ =0x080E14D9
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity778B_Init
	cmp r0, #0
	bge _080E1544
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080E1546
	.align 2, 0
_080E1538: .4byte 0x03000180
_080E153C: .4byte 0x080E13D5
_080E1540: .4byte 0x080E14D9
_080E1544:
	adds r0, r4, #0
_080E1546:
	pop {r4, r5}
	pop {r1}
	bx r1
