	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	movs r4, #0
	ldr r0, _0820ECF8 @ =0x00000854
	adds r0, r0, r6
	mov r8, r0
	ldr r1, _0820ECFC @ =0x000005B4
	adds r1, r1, r6
	mov ip, r1
	movs r3, #0x4c
	adds r3, r3, r6
	mov sl, r3
	movs r0, #0x26
	adds r0, r0, r6
	mov sb, r0
	movs r7, #1
_0820EC96:
	lsls r1, r4, #1
	adds r5, r4, #1
	adds r0, r1, r4
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820ECA4:
	ldr r0, [r2]
	orrs r0, r7
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820ECA4
	adds r1, r1, r4
	lsls r1, r1, #5
	add r1, ip
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	adds r4, r5, #0
	cmp r4, #6
	ble _0820EC96
	movs r3, #0
	ldr r1, _0820ED00 @ =0x0000084C
	adds r0, r6, r1
	mov r1, sb
	ldrb r2, [r1]
	adds r2, #1
	str r3, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	movs r1, #0x18
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r3, [sp, #0x10]
	mov r1, sl
	movs r3, #2
	bl FUN_082376a4
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820ECF8: .4byte 0x00000854
_0820ECFC: .4byte 0x000005B4
_0820ED00: .4byte 0x0000084C
