	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r7, #0
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r6, r7, r0
	adds r1, r7, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FB2FC
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FB2FE
_081FB2FC:
	movs r0, #0
_081FB2FE:
	cmp r0, #0
	beq _081FB310
	adds r0, r6, #0
	bl NestedState_Reset0
	movs r1, #4
	adds r0, r4, #0
	adds r0, #0xa2
	strb r1, [r0]
_081FB310:
	ldrb r0, [r6]
	cmp r0, #7
	bls _081FB318
	b _081FB50A
_081FB318:
	lsls r0, r0, #2
	ldr r1, _081FB324 @ =_081FB328
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FB324: .4byte _081FB328
_081FB328: @ jump table
	.4byte _081FB348 @ case 0
	.4byte _081FB3E4 @ case 1
	.4byte _081FB41C @ case 2
	.4byte _081FB450 @ case 3
	.4byte _081FB478 @ case 4
	.4byte _081FB4A0 @ case 5
	.4byte _081FB4AC @ case 6
	.4byte _081FB500 @ case 7
_081FB348:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB398
	add r1, sp, #8
	mov r8, r1
_081FB352:
	mov r0, sp
	movs r1, #0
	bl Map_PickRandomPathNode
	adds r4, r0, #0
	mov r0, r8
	movs r1, #0
	bl Map_PickRandomPathNode
	cmp r4, r0
	beq _081FB352
	ldr r3, _081FB394 @ =0x0000083C
	adds r5, r7, r3
	ldr r0, [r5]
	mov r1, sp
	bl FUN_08201054
	movs r0, #0x84
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r0, [r4]
	mov r1, r8
	bl FUN_08201054
	ldr r0, [r5]
	bl FUN_082010b4
	ldr r0, [r4]
	bl FUN_082010b4
	movs r0, #1
	b _081FB39A
	.align 2, 0
_081FB394: .4byte 0x0000083C
_081FB398:
	adds r0, #1
_081FB39A:
	str r0, [r6, #4]
	ldr r1, [r6, #4]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _081FB3AC
	cmp r1, #2
	beq _081FB3C4
	b _081FB3D4
_081FB3AC:
	ldr r1, _081FB3BC @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB3C0 @ =0x00000694
	adds r0, r0, r3
	bl FUN_081fae7c
	b _081FB3D4
	.align 2, 0
_081FB3BC: .4byte 0x0000083C
_081FB3C0: .4byte 0x00000694
_081FB3C4:
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB3E0 @ =0x00000694
	adds r0, r0, r3
	bl FUN_081fae7c
_081FB3D4:
	ldr r0, [r6, #4]
	cmp r0, #0x1e
	bhi _081FB3DC
	b _081FB50A
_081FB3DC:
	b _081FB4EA
	.align 2, 0
_081FB3E0: .4byte 0x00000694
_081FB3E4:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB410
	ldr r1, _081FB408 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FB40C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
	str r1, [r6, #4]
	b _081FB414
	.align 2, 0
_081FB408: .4byte 0x0000083C
_081FB40C: .4byte 0x000006DB
_081FB410:
	adds r0, #1
	str r0, [r6, #4]
_081FB414:
	ldr r0, [r6, #4]
	cmp r0, #0xa
	bls _081FB50A
	b _081FB4CC
_081FB41C:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB43A
	ldr r3, _081FB448 @ =0x0000083C
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r2, _081FB44C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	adds r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FB43A:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #0x8c
	bls _081FB50A
	b _081FB4EA
	.align 2, 0
_081FB448: .4byte 0x0000083C
_081FB44C: .4byte 0x000006DB
_081FB450:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB464
	ldr r1, _081FB470 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB474 @ =0x000006DB
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
_081FB464:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #0x1e
	bls _081FB50A
	b _081FB4EA
	.align 2, 0
_081FB470: .4byte 0x0000083C
_081FB474: .4byte 0x000006DB
_081FB478:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB48E
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB49C @ =0x000006DB
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
_081FB48E:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #0x1e
	bls _081FB50A
	b _081FB4EA
	.align 2, 0
_081FB49C: .4byte 0x000006DB
_081FB4A0:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #0x3c
	bls _081FB50A
	b _081FB4EA
_081FB4AC:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB4CC
	ldr r1, _081FB4F4 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FB4F8 @ =0x000006DB
	adds r0, r0, r2
	movs r1, #5
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FB4CC:
	ldr r1, _081FB4F4 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB4FC @ =0x000006D9
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FB50A
	adds r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FB50A
_081FB4EA:
	adds r0, r6, #0
	bl NestedState_Advance0
	b _081FB50A
	.align 2, 0
_081FB4F4: .4byte 0x0000083C
_081FB4F8: .4byte 0x000006DB
_081FB4FC: .4byte 0x000006D9
_081FB500:
	movs r3, #0xfb
	lsls r3, r3, #3
	adds r1, r7, r3
	movs r0, #1
	strh r0, [r1]
_081FB50A:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
