	push {r4, r5, lr}
	sub sp, #0x10
	bl fetch_082316e4
	adds r4, r0, #0
	bl fetch_082316e4
	adds r2, r0, #0
	mov r5, sp
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	adds r1, r4, #0
	bl FUN_08234f90
	cmp r0, #0
	blt _0823502C
	add r4, sp, #8
	adds r0, r4, #0
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
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
	movs r1, #4
	ldrsh r2, [r5, r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	movs r0, #0
	b _08235030
_0823502C:
	movs r0, #1
	rsbs r0, r0, #0
_08235030:
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
