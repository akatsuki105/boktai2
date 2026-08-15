	push {r4, lr}
	sub sp, #8
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FindUnk0200865c
	adds r4, r0, #0
	cmp r4, #0
	beq _0823B33C
	mov r0, sp
	bl FUN_0823167c
	movs r0, #8
	ldrsh r2, [r4, r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	movs r0, #0xc
	ldrsh r2, [r4, r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	movs r0, #0
	b _0823B370
_0823B33C:
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	movs r0, #1
	rsbs r0, r0, #0
_0823B370:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
