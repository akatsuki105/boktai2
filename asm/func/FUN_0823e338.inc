	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x10
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	mov r8, r0
	bl Script_GetValue
	adds r6, r0, #0
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	str r4, [sp]
	str r0, [sp, #4]
	mov r0, sb
	mov r1, r8
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_0823d9ec
	adds r4, r0, #0
	add r0, sp, #8
	bl FUN_0823167c
	add r0, sp, #8
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
