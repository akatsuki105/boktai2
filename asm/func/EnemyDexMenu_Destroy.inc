	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0xcc
	adds r0, r4, #0
	bl FUN_0820e75c
	adds r0, r7, #0
	adds r0, #0x6c
	bl FUN_0820e75c
	adds r0, r4, #0
	bl FUN_0820e75c
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r7, r1
	bl FUN_0820e75c
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_0820E7A2:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E7A2
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r5, r7, r1
	movs r4, #2
_0820E7B8:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E7B8
	ldr r1, _0820E868 @ =0x0000048C
	adds r0, r7, r1
	bl FUN_0820e75c
	ldr r1, _0820E86C @ =0x000004EC
	adds r0, r7, r1
	bl FUN_0820e75c
	ldr r1, _0820E870 @ =0x0000054C
	adds r0, r7, r1
	bl FUN_0820e75c
	ldr r0, _0820E874 @ =0x000008AC
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0820E878 @ =0x0000084C
	adds r6, r7, r1
	ldr r0, _0820E87C @ =0x000005AC
	adds r5, r7, r0
	movs r4, #6
_0820E7EE:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r0, r6, #0
	bl FUN_0820e75c
	mov r0, r8
	bl FUN_0820e75c
	movs r1, #0xc0
	add r8, r1
	adds r6, #0xc0
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E7EE
	ldr r0, _0820E880 @ =0x00000E4C
	adds r6, r7, r0
	ldr r1, _0820E884 @ =0x00000D8C
	adds r5, r7, r1
	movs r4, #1
_0820E818:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r0, r6, #0
	bl FUN_0820e75c
	adds r6, #0x60
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E818
	ldr r0, _0820E888 @ =0x00000F0C
	adds r5, r7, r0
	movs r4, #1
_0820E834:
	adds r0, r5, #0
	bl FUN_0820e75c
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0820E834
	ldr r1, _0820E88C @ =0x00000FCC
	adds r0, r7, r1
	bl FUN_0820e75c
	ldr r1, _0820E890 @ =0x0000102C
	adds r0, r7, r1
	bl MainSprite_Remove
	ldr r1, _0820E894 @ =0x0000108C
	adds r0, r7, r1
	bl MainSprite_Remove
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0820E868: .4byte 0x0000048C
_0820E86C: .4byte 0x000004EC
_0820E870: .4byte 0x0000054C
_0820E874: .4byte 0x000008AC
_0820E878: .4byte 0x0000084C
_0820E87C: .4byte 0x000005AC
_0820E880: .4byte 0x00000E4C
_0820E884: .4byte 0x00000D8C
_0820E888: .4byte 0x00000F0C
_0820E88C: .4byte 0x00000FCC
_0820E890: .4byte 0x0000102C
_0820E894: .4byte 0x0000108C
