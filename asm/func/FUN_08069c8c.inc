	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x12
	beq _08069CAC
	adds r0, r4, #0
	bl FUN_08060c60
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_08060b84
_08069CAC:
	ldr r1, _08069CC0 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08069CF2
	cmp r0, #1
	bgt _08069CC4
	cmp r0, #0
	beq _08069CCA
	b _08069D68
	.align 2, 0
_08069CC0: .4byte 0x0000037D
_08069CC4:
	cmp r0, #2
	beq _08069D42
	b _08069D68
_08069CCA:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x30
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069D68
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_08060b84
	b _08069D68
_08069CF2:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x31
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #1
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0xf3
	ands r0, r1
	cmp r0, #0
	beq _08069D20
	movs r2, #2
_08069D20:
	movs r0, #0xfb
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, r2
	ble _08069D32
	subs r0, r0, r2
	strh r0, [r1]
	b _08069D68
_08069D32:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #2
	bl FUN_08060b84
	b _08069D68
_08069D42:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x32
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08069D68
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08069D68:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
