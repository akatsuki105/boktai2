	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0820f840
FUN_0820f840: @ 0x0820F840
	push {lr}
	ldr r1, [r0, #0x1c]
	bl FUN_0820f9dc
	pop {r0}
	bx r0

	thumb_func_start FUN_0820f84c
FUN_0820f84c: @ 0x0820F84C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x20]
	movs r1, #0
	cmp r0, #0
	bne _0820F864
	movs r1, #1
_0820F864:
	adds r2, r0, #1
	str r2, [r6, #0x20]
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r0, [r0]
	movs r3, #0x24
	adds r3, r3, r6
	mov sb, r3
	ldrb r7, [r3]
	mov sl, sb
	cmp r7, #1
	beq _0820F8E4
	cmp r7, #1
	bgt _0820F888
	cmp r7, #0
	beq _0820F894
	b _0820F9CC
_0820F888:
	cmp r7, #2
	beq _0820F958
	cmp r7, #3
	bne _0820F892
	b _0820F9C0
_0820F892:
	b _0820F9CC
_0820F894:
	movs r2, #0x28
	adds r2, r2, r6
	mov r8, r2
	cmp r1, #0
	beq _0820F8C6
	ldrb r0, [r0, #0xa]
	ldr r3, _0820F8DC @ =0x00000366
	adds r4, r6, r3
	ldr r1, _0820F8E0 @ =0x00000367
	adds r5, r6, r1
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0820efc4
	ldrb r2, [r4]
	ldrb r3, [r5]
	movs r0, #2
	str r0, [sp]
	str r7, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r1, #1
	bl FUN_08055b5c
_0820F8C6:
	mov r0, r8
	bl FUN_08055c04
	adds r2, r0, #0
	cmp r2, #0
	bne _0820F8D4
	b _0820F9CC
_0820F8D4:
	str r7, [r6, #0x20]
	movs r0, #1
	b _0820F9C8
	.align 2, 0
_0820F8DC: .4byte 0x00000366
_0820F8E0: .4byte 0x00000367
_0820F8E4:
	movs r3, #0x28
	adds r3, r3, r6
	mov r8, r3
	cmp r1, #0
	beq _0820F918
	ldrb r0, [r0, #0xa]
	ldr r1, _0820F934 @ =0x00000366
	adds r4, r6, r1
	ldr r2, _0820F938 @ =0x00000367
	adds r5, r6, r2
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0820efc4
	ldrb r2, [r4]
	ldrb r3, [r5]
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r1, #2
	bl FUN_08055b5c
_0820F918:
	mov r0, r8
	bl FUN_08055c04
	adds r2, r0, #0
	ldr r0, [r6, #0x20]
	cmp r0, #0xb
	bhi _0820F93C
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldrh r0, [r1, #2]
	subs r0, #1
	b _0820F946
	.align 2, 0
_0820F934: .4byte 0x00000366
_0820F938: .4byte 0x00000367
_0820F93C:
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldrh r0, [r1, #2]
	adds r0, #1
_0820F946:
	strh r0, [r1, #2]
	cmp r2, #0
	beq _0820F9CC
	movs r0, #0
	str r0, [r6, #0x20]
	movs r0, #2
	mov r3, sl
	strb r0, [r3]
	b _0820F9CC
_0820F958:
	movs r2, #0x28
	adds r2, r2, r6
	mov r8, r2
	cmp r1, #0
	beq _0820F99E
	ldrb r0, [r0, #0xa]
	ldr r3, _0820F9B8 @ =0x00000366
	adds r4, r6, r3
	ldr r1, _0820F9BC @ =0x00000367
	adds r5, r6, r1
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0820efc4
	ldrb r2, [r4]
	ldrb r3, [r5]
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r1, #3
	bl FUN_08055b5c
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r3, #0xd5
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_0820F99E:
	mov r0, r8
	bl FUN_08055c04
	adds r2, r0, #0
	cmp r2, #0
	beq _0820F9CC
	movs r0, #0
	str r0, [r6, #0x20]
	movs r0, #3
	mov r1, sb
	strb r0, [r1]
	b _0820F9CC
	.align 2, 0
_0820F9B8: .4byte 0x00000366
_0820F9BC: .4byte 0x00000367
_0820F9C0:
	cmp r2, #0x1e
	bls _0820F9CC
	movs r0, #0
	str r0, [r6, #0x20]
_0820F9C8:
	mov r2, sb
	strb r0, [r2]
_0820F9CC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

