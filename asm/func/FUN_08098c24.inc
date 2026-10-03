	push {r4, r5, r6, lr}
	sub sp, #0x2c
	adds r5, r0, #0
	ldr r1, _08098CC8 @ =0x00004004
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _08098CCC @ =0x00004008
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	cmp r1, #0x63
	ble _08098C3E
	movs r1, #0x63
_08098C3E:
	lsls r3, r1, #2
	adds r3, r3, r1
	lsls r3, r3, #1
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r6, #5
	str r6, [sp]
	movs r0, #7
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0808a4ac
	ldr r2, _08098CD0 @ =0x00004005
	adds r0, r5, r2
	ldrb r1, [r0]
	ldr r3, _08098CD4 @ =0x00004009
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r1, r1, r0
	cmp r1, #0x63
	ble _08098C78
	movs r1, #0x63
_08098C78:
	lsls r3, r1, #2
	adds r3, r3, r1
	adds r3, #0x64
	ldr r0, [r4]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	str r6, [sp]
	movs r0, #8
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0808a4ac
	ldr r6, _08098CD8 @ =0x030046A0
	ldr r0, [r6]
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	add r1, sp, #8
	bl FUN_08242b28
	add r0, sp, #8
	ldrb r0, [r0, #1]
	adds r2, r0, #0
	cmp r2, #4
	bne _08098CDC
	add r0, sp, #8
	bl FUN_0807a6cc
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	movs r2, #6
	movs r3, #9
	bl FUN_0808b30c
	b _08098D40
	.align 2, 0
_08098CC8: .4byte 0x00004004
_08098CCC: .4byte 0x00004008
_08098CD0: .4byte 0x00004005
_08098CD4: .4byte 0x00004009
_08098CD8: .4byte 0x030046A0
_08098CDC:
	ldr r3, _08098D18 @ =0x00004006
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, #4
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r1, r1, r0
	cmp r1, #0x63
	ble _08098CF0
	movs r1, #0x63
_08098CF0:
	ldr r0, [r6]
	adds r0, #0x40
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r1, r0
	asrs r4, r0, #1
	cmp r2, #3
	bne _08098D1C
	movs r0, #3
	bl GetWeaponSkillLevel
	ldr r1, [r6]
	adds r1, #0x40
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	asrs r0, r0, #2
	adds r4, r4, r0
	b _08098D30
	.align 2, 0
_08098D18: .4byte 0x00004006
_08098D1C:
	add r0, sp, #8
	adds r1, r0, #0
	movs r3, #8
	ldrsh r1, [r1, r3]
	ldrb r0, [r0, #4]
	adds r1, r1, r0
	cmp r1, #0
	bge _08098D2E
	movs r1, #0
_08098D2E:
	adds r4, r4, r1
_08098D30:
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0x64
	movs r2, #6
	movs r3, #9
	bl FUN_0808b30c
_08098D40:
	ldr r1, _08098D88 @ =0x00004007
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _08098D8C @ =0x0000400B
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	cmp r1, #0x63
	ble _08098D54
	movs r1, #0x63
_08098D54:
	ldr r0, _08098D90 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r1, r0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	ldr r3, _08098D94 @ =0x00000266
	adds r1, r1, r3
	asrs r0, r0, #1
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	movs r2, #6
	movs r3, #0xa
	bl FUN_0808b30c
	add sp, #0x2c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098D88: .4byte 0x00004007
_08098D8C: .4byte 0x0000400B
_08098D90: .4byte 0x030046A0
_08098D94: .4byte 0x00000266
