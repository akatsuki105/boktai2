	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08140A6C
	adds r2, #0xce
	adds r0, r5, r2
	strh r1, [r0]
	b _08140B28
_08140A6C:
	ldr r0, _08140A7C @ =0x0000024E
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08140A80
	subs r0, #1
	strh r0, [r1]
	b _08140B28
	.align 2, 0
_08140A7C: .4byte 0x0000024E
_08140A80:
	adds r0, r5, #0
	bl EnemyBat_PickRandomPathNode
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08140ABA
	cmp r1, #0
	blt _08140ABA
	ldr r0, _08140AC0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08140ABA
	ldr r0, _08140AC4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08140AC8
_08140ABA:
	movs r4, #0
	b _08140AD6
	.align 2, 0
_08140AC0: .4byte 0x030046A8
_08140AC4: .4byte 0x030046AC
_08140AC8:
	ldr r0, _08140AE8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08140AD6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08140AEC
	adds r0, #4
	b _08140AF8
	.align 2, 0
_08140AE8: .4byte 0x030046A4
_08140AEC:
	ldr r0, _08140B0C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08140AF8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08140B10
	cmp r2, #2
	beq _08140B14
	b _08140B18
	.align 2, 0
_08140B0C: .4byte 0x030046A4
_08140B10:
	ldrb r0, [r6, #4]
	b _08140B16
_08140B14:
	ldrb r0, [r6]
_08140B16:
	subs r1, r1, r0
_08140B18:
	strh r1, [r6, #2]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_08140970
	adds r0, r5, #0
	bl FUN_08140a10
_08140B28:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
