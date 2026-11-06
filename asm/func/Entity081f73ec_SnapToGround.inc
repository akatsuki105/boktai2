	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r0, #0
	mov sl, r0
	mov sb, r0
	mov r5, r8
	mov r7, r8
	adds r7, #0x1c
_081F5B94:
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F5BB8
	cmp r1, #0
	blt _081F5BB8
	ldr r0, _081F5BBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F5BB8
	ldr r0, _081F5BC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F5BC4
_081F5BB8:
	movs r4, #0
	b _081F5BD2
	.align 2, 0
_081F5BBC: .4byte 0x030046A8
_081F5BC0: .4byte 0x030046AC
_081F5BC4:
	ldr r0, _081F5BE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F5BD2:
	adds r6, r7, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F5BE8
	adds r0, #4
	b _081F5BF4
	.align 2, 0
_081F5BE4: .4byte 0x030046A4
_081F5BE8:
	ldr r0, _081F5C08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F5BF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F5C0C
	cmp r2, #2
	beq _081F5C10
	b _081F5C14
	.align 2, 0
_081F5C08: .4byte 0x030046A4
_081F5C0C:
	ldrb r0, [r6, #4]
	b _081F5C12
_081F5C10:
	ldrb r0, [r6]
_081F5C12:
	subs r1, r1, r0
_081F5C14:
	movs r2, #2
	ldrsh r0, [r7, r2]
	cmp r0, r1
	beq _081F5C7C
	cmp r0, r1
	bge _081F5C6E
	subs r0, r1, r0
	cmp r0, #0
	bge _081F5C28
	rsbs r0, r0, #0
_081F5C28:
	cmp r0, #0xff
	ble _081F5C46
	movs r0, #0xdb
	lsls r0, r0, #3
	add r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0, #0x1e]
	strh r0, [r5, #0x1e]
	b _081F5C7C
_081F5C46:
	strh r1, [r5, #0x1e]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _081F5C62
	adds r0, r5, #0
	adds r0, #0x1c
	movs r1, #1
	bl Entity081f73ec_SpawnDust
	movs r0, #0x1e
	strh r0, [r4]
_081F5C62:
	mov r2, sb
	cmp r2, #5
	bne _081F5C7C
	movs r0, #1
	mov sl, r0
	b _081F5C7C
_081F5C6E:
	subs r0, r1, r0
	movs r1, #0x1e
	bl Div
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
_081F5C7C:
	movs r2, #0x92
	lsls r2, r2, #1
	adds r5, r5, r2
	adds r7, r7, r2
	movs r0, #1
	add sb, r0
	mov r2, sb
	cmp r2, #5
	bgt _081F5C90
	b _081F5B94
_081F5C90:
	ldr r4, _081F5CB8 @ =0x000006DB
	add r4, r8
	ldrb r0, [r4]
	cmp r0, #0
	bne _081F5CAA
	mov r0, sl
	cmp r0, #0
	beq _081F5CAA
	ldr r0, _081F5CBC @ =0x000003D9
	bl PlaySound_082406e0
	movs r0, #0x14
	strb r0, [r4]
_081F5CAA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F5CB8: .4byte 0x000006DB
_081F5CBC: .4byte 0x000003D9
