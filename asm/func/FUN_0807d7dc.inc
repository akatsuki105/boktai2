	push {r4, r5, r6, lr}
	bl FUN_0807afe8
	ldr r1, _0807D800 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D822
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0807D804
	bl Script_GetValue
	adds r6, r0, #0
	b _0807D806
	.align 2, 0
_0807D800: .4byte 0x03002BE0
_0807D804:
	movs r6, #0x32
_0807D806:
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r3, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0807c084
	adds r0, r5, #0
	bl FUN_08072640
_0807D822:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
