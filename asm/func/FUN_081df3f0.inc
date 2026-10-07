	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF42C
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl TextPanel_Create
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r4, r5, r1
	str r0, [r4]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0xa
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
_081DF42C:
	adds r0, r5, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF444
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF454
_081DF444:
	ldr r1, [r5, #0x34]
	cmp r1, #0x77
	bls _081DF454
	ldr r2, _081DF45C @ =FUN_081df460
	adds r0, r5, #0
	movs r1, #0x15
	bl Entity9A9F_SetState
_081DF454:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DF45C: .4byte FUN_081df460
