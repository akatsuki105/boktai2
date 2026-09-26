	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DD8C0
	bl FUN_0823d340
	ldr r2, _081DD934 @ =0x0000083C
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081DD954
_081DD8C0:
	movs r0, #0
	bl FUN_081df8f0
	ldr r0, _081DD938 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081DD8D4
	ldrh r1, [r0, #0x1a]
_081DD8D4:
	ldr r2, _081DD93C @ =0x00000859
	adds r0, r4, r2
	movs r5, #0
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _081DD954
	adds r0, r4, #0
	bl FUN_081dc6d0
	adds r0, r4, #0
	bl FUN_081dc788
	adds r0, r4, #0
	bl FUN_081dc9dc
	adds r0, r4, #0
	bl FUN_081dcaa4
	adds r0, r4, #0
	bl FUN_081dcd50
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_081dce14
	ldr r1, _081DD940 @ =0x00000858
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_081dd2dc
	ldr r1, _081DD944 @ =FUN_081dd774
	ldr r2, _081DD948 @ =0x00000838
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _081DD94C @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD950 @ =0x00000854
	adds r0, r4, r1
	strb r5, [r0]
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #1
	b _081DD958
	.align 2, 0
_081DD934: .4byte 0x0000083C
_081DD938: .4byte 0x03002C68
_081DD93C: .4byte 0x00000859
_081DD940: .4byte 0x00000858
_081DD944: .4byte FUN_081dd774
_081DD948: .4byte 0x00000838
_081DD94C: .4byte 0x00000855
_081DD950: .4byte 0x00000854
_081DD954:
	movs r0, #1
	rsbs r0, r0, #0
_081DD958:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
