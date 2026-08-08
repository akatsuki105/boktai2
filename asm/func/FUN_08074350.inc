	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0807436C
	ldr r0, _08074368 @ =0x00000951
	adds r1, r4, r0
	movs r0, #9
	b _08074372
	.align 2, 0
_08074368: .4byte 0x00000951
_0807436C:
	ldr r0, _0807438C @ =0x00000951
	adds r1, r4, r0
	movs r0, #8
_08074372:
	strb r0, [r1]
	ldr r1, _08074390 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08074380
	b _080744B4
_08074380:
	lsls r0, r0, #2
	ldr r1, _08074394 @ =_08074398
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807438C: .4byte 0x00000951
_08074390: .4byte 0x0000037D
_08074394: .4byte _08074398
_08074398: @ jump table
	.4byte _080743B0 @ case 0
	.4byte _080743E8 @ case 1
	.4byte _08074402 @ case 2
	.4byte _0807442A @ case 3
	.4byte _08074452 @ case 4
	.4byte _0807448C @ case 5
_080743B0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080744B4
	ldr r0, _080743E4 @ =0x000001F7
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	adds r0, r4, #0
	bl FUN_080726b4
	b _080744B4
	.align 2, 0
_080743E4: .4byte 0x000001F7
_080743E8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080744B4
_08074402:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080744B4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _080744B4
_0807442A:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080744B4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _080744B4
_08074452:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08074488 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080744B4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _080744B4
	.align 2, 0
_08074488: .4byte 0x0000037E
_0807448C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080744B4
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_080744B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
