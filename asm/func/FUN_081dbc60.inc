	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DBCD8 @ =0x0000CB05
	ldr r1, _081DBCDC @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xc8
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenMainSpriteFile
	movs r0, #4
	mov r8, r0
	movs r7, #0
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r6, r5, r1
_081DBC92:
	mov r2, r8
	lsls r4, r2, #1
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r0, r5, r3
	adds r0, r0, r4
	ldrh r2, [r0]
	str r7, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r6, #0
	subs r3, #0x40
	adds r1, r5, r3
	movs r3, #0x10
	bl MainSprite_Add
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r4
	ldr r1, _081DBCE0 @ =0x0000FFFF
	strh r1, [r0]
	adds r6, #0x60
	movs r2, #1
	add r8, r2
	mov r3, r8
	cmp r3, #7
	ble _081DBC92
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DBCD8: .4byte 0x0000CB05
_081DBCDC: .4byte 0x0000DCC1
_081DBCE0: .4byte 0x0000FFFF
