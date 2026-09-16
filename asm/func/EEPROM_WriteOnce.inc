	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r1
	mov r8, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	asrs r7, r2, #3
	mov r4, sb
	mov r5, sl
	movs r6, #0
	cmp r6, r7
	bge _08243788
_0824376E:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl EEPROMWrite1
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243814
	adds r4, #8
	adds r5, #1
	adds r6, #1
	cmp r6, r7
	blt _0824376E
_08243788:
	mov r4, sb
	mov r5, sl
	movs r6, #0
	cmp r6, r7
	bge _082437AC
_08243792:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl EEPROMCompare
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243814
	adds r4, #8
	adds r5, #1
	adds r6, #1
	cmp r6, r7
	blt _08243792
_082437AC:
	mov r0, sp
	movs r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	mov r1, r8
	asrs r0, r1, #1
	lsls r7, r5, #0x10
	cmp r0, #0
	ble _082437E0
	mov r4, sp
	mov r1, sb
	ldrh r3, [r4]
	movs r5, #0
	adds r6, r0, #0
_082437C8:
	ldrh r0, [r1]
	adds r2, r3, #0
	eors r2, r0
	adds r3, r2, #0
	adds r0, r5, r0
	adds r5, r0, #0
	adds r1, #2
	subs r6, #1
	cmp r6, #0
	bne _082437C8
	strh r0, [r4, #2]
	strh r2, [r4]
_082437E0:
	mov r0, sp
	mov r1, r8
	strh r1, [r0, #4]
	mov r1, sp
	ldr r0, _08243810 @ =0x0000FFFF
	strh r0, [r1, #6]
	lsrs r4, r7, #0x10
	adds r0, r4, #0
	bl EEPROMWrite1
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243814
	adds r0, r4, #0
	mov r1, sp
	bl EEPROMCompare
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243814
	movs r0, #8
	add r8, r0
	mov r0, r8
	b _08243818
	.align 2, 0
_08243810: .4byte 0x0000FFFF
_08243814:
	movs r0, #1
	rsbs r0, r0, #0
_08243818:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
