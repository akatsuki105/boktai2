	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl TextPanel_FindByID
	adds r5, r0, #0
	cmp r5, #0
	bne _0804A298
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A2EE
_0804A298:
	adds r4, r5, #0
	adds r4, #0x5c
	str r6, [r5, #0x10]
	adds r0, r5, #0
	movs r1, #0
	bl TextPanel_LookupText
	str r0, [r4, #0x1c]
	mov r0, r8
	strh r0, [r5, #0x14]
	strh r7, [r5, #0x16]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	adds r6, r4, #0
	cmp r0, #0x20
	bls _0804A2BC
	movs r0, #0x20
	strh r0, [r5, #0x16]
_0804A2BC:
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r0, [r5, #0x16]
	cmp r3, r0
	bge _0804A2DC
	ldr r2, [sp, #0x18]
	adds r1, r4, #0
_0804A2CC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	ldrh r0, [r5, #0x16]
	cmp r3, r0
	blt _0804A2CC
_0804A2DC:
	ldrh r0, [r5, #0x14]
	lsls r0, r0, #1
	adds r0, r4, r0
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	adds r0, r6, #0
	bl FUN_08049640
	movs r0, #0
_0804A2EE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
