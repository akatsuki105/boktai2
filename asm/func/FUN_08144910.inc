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
	bne _08144934
	adds r2, #0xce
	adds r0, r5, r2
	strh r1, [r0]
	b _081449F0
_08144934:
	ldr r0, _08144944 @ =0x0000024E
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08144948
	subs r0, #1
	strh r0, [r1]
	b _081449F0
	.align 2, 0
_08144944: .4byte 0x0000024E
_08144948:
	adds r0, r5, #0
	bl Crow_PickRandomPathNode
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
	blt _08144982
	cmp r1, #0
	blt _08144982
	ldr r0, _08144988 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08144982
	ldr r0, _0814498C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08144990
_08144982:
	movs r4, #0
	b _0814499E
	.align 2, 0
_08144988: .4byte 0x030046A8
_0814498C: .4byte 0x030046AC
_08144990:
	ldr r0, _081449B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814499E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081449B4
	adds r0, #4
	b _081449C0
	.align 2, 0
_081449B0: .4byte 0x030046A4
_081449B4:
	ldr r0, _081449D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081449C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081449D8
	cmp r2, #2
	beq _081449DC
	b _081449E0
	.align 2, 0
_081449D4: .4byte 0x030046A4
_081449D8:
	ldrb r0, [r6, #4]
	b _081449DE
_081449DC:
	ldrb r0, [r6]
_081449DE:
	subs r1, r1, r0
_081449E0:
	strh r1, [r6, #2]
	adds r0, r5, #0
	mov r1, sp
	bl Crow_BeginCurveMove
	adds r0, r5, #0
	bl FUN_081448d8
_081449F0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
