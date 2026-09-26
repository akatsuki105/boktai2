	push {r4, lr}
	adds r4, r0, #0
	bl Credits_TakeStepChanged
	ldrb r1, [r4, #0x1a]
	lsls r1, r1, #1
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, [r4, #0x20]
	cmp r0, r1
	blo _0804A75E
	ldr r1, _0804A74C @ =0x03004040
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r4, #0x1a]
	ldrb r1, [r4, #0x1b]
	cmp r0, r1
	bne _0804A750
	bl TextBox_Close
	adds r0, r4, #0
	movs r1, #4
	bl Credits_SetStep
	ldrh r0, [r4, #0x30]
	cmp r0, #0
	beq _0804A73A
	movs r1, #0
	bl VM_ExecByID
_0804A73A:
	ldrh r1, [r4, #0x24]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804A76C
	adds r0, r4, #0
	bl KillEntity
	b _0804A76C
	.align 2, 0
_0804A74C: .4byte 0x03004040
_0804A750:
	adds r0, #1
	strb r0, [r4, #0x1a]
	adds r0, r4, #0
	movs r1, #0
	bl Credits_SetStep
	b _0804A76C
_0804A75E:
	ldr r4, _0804A774 @ =0x03004040
	lsls r0, r0, #6
	bl Div
	movs r1, #0x40
	subs r1, r1, r0
	str r1, [r4]
_0804A76C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A774: .4byte 0x03004040
