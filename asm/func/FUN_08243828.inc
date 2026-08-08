	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r1, #0
	mov r8, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r7, r2, #3
	mov sb, r5
	movs r6, #0
	cmp r6, r7
	bge _08243860
_08243844:
	adds r0, r4, #0
	adds r1, r5, #0
	bl EEPROMRead
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _082438C8
	adds r5, #8
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, #1
	cmp r6, r7
	blt _08243844
_08243860:
	adds r0, r4, #0
	mov r1, sp
	bl EEPROMRead
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _082438C8
	add r0, sp, #8
	strh r5, [r0]
	strh r5, [r0, #2]
	mov r1, r8
	asrs r2, r1, #1
	adds r7, r0, #0
	cmp r5, r2
	bge _082438A4
	mov ip, r7
	movs r4, #0
	movs r3, #0
	mov r1, sb
	adds r6, r2, #0
_0824388A:
	ldrh r0, [r1]
	adds r2, r4, #0
	eors r2, r0
	adds r4, r2, #0
	adds r0, r3, r0
	adds r3, r0, #0
	adds r1, #2
	subs r6, #1
	cmp r6, #0
	bne _0824388A
	mov r1, ip
	strh r0, [r1, #2]
	strh r2, [r1]
_082438A4:
	mov r0, sp
	ldrh r1, [r7]
	ldrh r0, [r0]
	eors r1, r0
	strh r1, [r7]
	cmp r5, #0
	bne _082438C8
	cmp r1, #0
	bne _082438C8
	mov r0, sp
	ldrh r1, [r7, #2]
	ldrh r0, [r0, #2]
	cmp r1, r0
	bne _082438C8
	mov r0, sp
	ldrh r0, [r0, #4]
	cmp r8, r0
	beq _082438CE
_082438C8:
	movs r0, #1
	rsbs r0, r0, #0
	b _082438D0
_082438CE:
	movs r0, #0
_082438D0:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
