	push {lr}
	adds r2, r0, #0
	movs r1, #6
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E7F4E
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E8030
_080E7F4E:
	ldr r1, _080E7F64 @ =0x000001DF
	adds r0, r2, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1d
	bhi _080E8030
	lsls r0, r0, #2
	ldr r1, _080E7F68 @ =_080E7F6C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E7F64: .4byte 0x000001DF
_080E7F68: .4byte _080E7F6C
_080E7F6C: @ jump table
	.4byte _080E7FEC @ case 0
	.4byte _080E8030 @ case 1
	.4byte _080E7FF4 @ case 2
	.4byte _080E7FE4 @ case 3
	.4byte _080E8030 @ case 4
	.4byte _080E8030 @ case 5
	.4byte _080E8030 @ case 6
	.4byte _080E8030 @ case 7
	.4byte _080E8030 @ case 8
	.4byte _080E802A @ case 9
	.4byte _080E8030 @ case 10
	.4byte _080E8030 @ case 11
	.4byte _080E8030 @ case 12
	.4byte _080E8020 @ case 13
	.4byte _080E8030 @ case 14
	.4byte _080E8030 @ case 15
	.4byte _080E8030 @ case 16
	.4byte _080E8030 @ case 17
	.4byte _080E8030 @ case 18
	.4byte _080E8030 @ case 19
	.4byte _080E8030 @ case 20
	.4byte _080E8030 @ case 21
	.4byte _080E8030 @ case 22
	.4byte _080E8030 @ case 23
	.4byte _080E8030 @ case 24
	.4byte _080E8030 @ case 25
	.4byte _080E8030 @ case 26
	.4byte _080E7FE4 @ case 27
	.4byte _080E8030 @ case 28
	.4byte _080E7FF4 @ case 29
_080E7FE4:
	movs r0, #0xd4
	bl PlaySound_082406e0
	b _080E8030
_080E7FEC:
	movs r0, #0xfd
	bl PlaySound_082406e0
	b _080E8030
_080E7FF4:
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #3
	beq _080E8012
	cmp r0, #3
	bgt _080E800E
	cmp r0, #1
	bgt _080E8030
	cmp r0, #0
	blt _080E8030
	b _080E8012
_080E800E:
	cmp r0, #5
	bne _080E8030
_080E8012:
	ldr r0, _080E801C @ =0x0000018D
	bl PlaySound_082406e0
	b _080E8030
	.align 2, 0
_080E801C: .4byte 0x0000018D
_080E8020:
	movs r0, #0xee
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E8030
_080E802A:
	ldr r0, _080E8034 @ =0x000001CD
	bl PlaySound_082406e0
_080E8030:
	pop {r0}
	bx r0
	.align 2, 0
_080E8034: .4byte 0x000001CD
