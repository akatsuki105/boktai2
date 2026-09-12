	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r7, r1, #3
	add r0, sp, #8
	movs r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	movs r5, #0
	mov r8, r0
	cmp r5, r7
	bge _08243940
	add r0, sp, #0xc
	mov sb, r0
_08243908:
	adds r0, r4, #0
	add r1, sp, #0xc
	bl EEPROMRead
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243970
	adds r6, r4, #1
	adds r5, #1
	mov r2, r8
	mov r3, sb
	movs r4, #3
_08243920:
	ldrh r0, [r2]
	ldrh r1, [r3]
	eors r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r2, #2]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _08243920
	lsls r0, r6, #0x10
	lsrs r4, r0, #0x10
	cmp r5, r7
	blt _08243908
_08243940:
	adds r0, r4, #0
	mov r1, sp
	bl EEPROMRead
	lsls r0, r0, #0x10
	mov r1, sp
	mov r3, r8
	ldrh r2, [r3]
	ldrh r1, [r1]
	eors r2, r1
	strh r2, [r3]
	cmp r0, #0
	bne _08243970
	cmp r2, #0
	bne _08243970
	mov r0, sp
	ldrh r1, [r3, #2]
	ldrh r0, [r0, #2]
	cmp r1, r0
	bne _08243970
	mov r0, sp
	ldrh r0, [r0, #4]
	cmp sl, r0
	beq _08243976
_08243970:
	movs r0, #1
	rsbs r0, r0, #0
	b _08243978
_08243976:
	movs r0, #0
_08243978:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
