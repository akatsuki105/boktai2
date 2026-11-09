	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DBDE8 @ =0x0000CB05
	ldr r1, _081DBDEC @ =0x0000DE23
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenMainSpriteFile
	movs r4, #0
	mov sb, r4
	movs r7, #0
	adds r6, r5, #0
	adds r6, #0x20
	movs r0, #0
	mov r8, r0
_081DBDAA:
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r3, r8
	str r3, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r3, #0x10
	bl MainSprite_Add
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r7
	ldr r1, _081DBDF0 @ =0x0000FFFF
	strh r1, [r0]
	cmp r4, #1
	beq _081DBE02
	cmp r4, #1
	bgt _081DBDF4
	cmp r4, #0
	beq _081DBDFE
	b _081DBE0E
	.align 2, 0
_081DBDE8: .4byte 0x0000CB05
_081DBDEC: .4byte 0x0000DE23
_081DBDF0: .4byte 0x0000FFFF
_081DBDF4:
	cmp r4, #2
	beq _081DBE06
	cmp r4, #3
	beq _081DBE0A
	b _081DBE0E
_081DBDFE:
	movs r3, #0x22
	b _081DBE10
_081DBE02:
	movs r3, #0x23
	b _081DBE10
_081DBE06:
	movs r3, #0x24
	b _081DBE10
_081DBE0A:
	movs r3, #0x25
	b _081DBE10
_081DBE0E:
	movs r3, #0
_081DBE10:
	adds r1, r5, #0
	adds r1, #0x68
	add r1, sb
	ldr r0, _081DBE40 @ =0x03003584
	lsls r2, r3, #5
	ldr r0, [r0]
	adds r0, r0, r2
	str r0, [r1]
	strh r3, [r6, #0x3a]
	movs r2, #0x60
	add sb, r2
	adds r7, #2
	adds r6, #0x60
	adds r4, #1
	cmp r4, #3
	ble _081DBDAA
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DBE40: .4byte 0x03003584
