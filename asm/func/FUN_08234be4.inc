	push {r4, r5, lr}
	sub sp, #0xc
	bl FUN_082316bc
	cmp r0, #0
	beq _08234C04
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_0823492c
	adds r5, r0, #0
	cmp r5, #0
	bne _08234C0A
_08234C04:
	movs r0, #1
	rsbs r0, r0, #0
	b _08234CF0
_08234C0A:
	add r4, sp, #4
	adds r0, r4, #0
	bl FUN_0823167c
	movs r0, #0
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #8]
	lsls r2, r2, #4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	movs r0, #2
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	movs r0, #4
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #9]
	lsls r2, r2, #4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	movs r0, #6
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	adds r3, r4, #0
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #0
	ldrsh r0, [r5, r2]
	adds r0, r1, r0
	cmp r0, #0
	blt _08234C92
	asrs r2, r0, #1
	b _08234C98
_08234C92:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r2, r0, #0
_08234C98:
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	adds r3, r4, #0
	ldrb r1, [r5, #9]
	ldrb r0, [r5, #8]
	adds r0, r1, r0
	cmp r0, #0
	blt _08234CB6
	asrs r0, r0, #1
	b _08234CBC
_08234CB6:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08234CBC:
	lsls r2, r0, #4
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	adds r3, r4, #0
	movs r0, #6
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r0, r1, r0
	cmp r0, #0
	blt _08234CE0
	asrs r2, r0, #1
	b _08234CE6
_08234CE0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r2, r0, #0
_08234CE6:
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0823206c
	movs r0, #0
_08234CF0:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
